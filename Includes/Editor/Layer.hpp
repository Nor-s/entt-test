//
// Created by No on 2023-03-05.
//

#ifndef MINA_LAYER_HPP
#define MINA_LAYER_HPP

namespace Mina {

class Layer {
public:
	Layer() = default;
	virtual ~Layer() = default;
	 virtual void update(class Scene& scene) = 0;
};

}

#endif	  // MINA_LAYER_HPP
