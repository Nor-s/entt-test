//
// Created by No on 2023-03-14.
//

#ifndef MINA_COMMAND_HPP
#define MINA_COMMAND_HPP

#include "../pch.hpp"
#include "Singleton.hpp"

namespace Mina
{

class CommandExecutor;

class Command
{
	friend class CommandExecutor;

private:
	double time{};

public:
	Command() = default;
	virtual ~Command() = default;
	virtual void execute() = 0;
	[[maybe_unused]] virtual void undo()
	{
	}
	[[maybe_unused]] virtual void update()
	{
	}
	[[nodiscard]] virtual bool canUndo() const
	{
		return false;
	}
};

class CommandExecutor : public Singleton<CommandExecutor>
{
	friend class Singleton<CommandExecutor>;
private:
	std::vector<std::unique_ptr<Command>> deferredCommands;
	std::vector<std::unique_ptr<Command>> commandHistory;
	unsigned int historyIndex{0u};

private:
	CommandExecutor()
	{
		commandHistory.resize(64);
		deferredCommands.reserve(32);
	}

	void addHistory(std::unique_ptr<Command> command)
	{
		if (command->canUndo())
		{
			commandHistory[historyIndex].reset();
			commandHistory[historyIndex] = std::move(command);
			{
				auto now = std::chrono::system_clock::now();
				auto duration = now.time_since_epoch();
				commandHistory[historyIndex]->time = std::chrono::duration<double>(duration).count();
			}
			historyIndex = (historyIndex + 1) % commandHistory.size();
		}
	}

public:
	virtual ~CommandExecutor() = default;

	template <typename T, typename... Args>
	void execute(Args&&... args)
	{
		auto command = std::make_unique<T>(std::forward<Args>(args)...);
		command->exec();
		addHistory(std::move(command));
	}

	template <typename T, typename... Args>
	[[maybe_unused]] void deferExecute(Args&&... args)
	{
		deferredCommands.emplace_back(new T(std::forward<Args>(args)...));
	}

	void executeAll()
	{
		for (auto& deferredCommand : deferredCommands)
		{
			deferredCommand->execute();
			addHistory(std::move(deferredCommand));
		}
		deferredCommands.clear();
	}

	void undo()
	{
		auto beforeIndex = (historyIndex + commandHistory.size() - 1) % commandHistory.size();
		if (commandHistory[beforeIndex])
		{
			if (commandHistory[beforeIndex]->time <= commandHistory[historyIndex]->time)
			{
				commandHistory[beforeIndex]->undo();
				historyIndex = beforeIndex;
			}
		}
	}

	void redo()
	{
		auto beforeIndex = (historyIndex + commandHistory.size() - 1) % commandHistory.size();
		if (commandHistory[beforeIndex] && commandHistory[historyIndex])
		{
			if (deferredCommands[beforeIndex]->time <= commandHistory[historyIndex]->time)
			{
				commandHistory[historyIndex]->execute();
				historyIndex = (historyIndex + 1) % commandHistory.size();
			}
		}
	}
};

}	 // namespace Mina

#endif	  // MINA_COMMAND_HPP
