#include "ERS/src/EntityRegistrySystem.h"

//Definition of component is all that is required to create it
struct Vec2 {
	float x, y;
};
struct TransformComponent2D {
	Vec2 position = { 0,0 };
};

struct PhysicsComponent2D {
	float gravity = 9.8f;
};

//	If your component uses custom memory allocation (such as new keyword), then
//	you need to write memory deallocation logic in component destructor, and then use
//	delete_component<T>(id) method manually

//Example
struct TextureComponent {
	void* texture;
	~TextureComponent() {
		delete texture;
	}
};


int main() {

	//Initialising ERS
	EntityRegistrySystem ers;

	//Adding entities to registry
	entity_id_t entity1 = ers.add_entity();
	entity_id_t entity2 = ers.add_entity();

	//Add components
	auto transform1 = ers.add_component<TransformComponent2D>(entity1);
	auto physics1 = ers.add_component<PhysicsComponent2D>(entity1);

	//You can change values of componets directly on create
	ers.add_component<PhysicsComponent2D>(entity2)->gravity = 5;

	//Change component value
	transform1->position.x = 10;

	//Get set of entities with common components
	for (entity_id_t entity : ers.get_by_common_components<PhysicsComponent2D, TransformComponent2D>()) {

		//Print entitiy IDs
		std::cout << '\n' << "ID: " << (uint32_t)entity;
	}

	//Get set of pointer to all occurrences of specific component
	for (TransformComponent2D* transform : ers.get_every_component_data<TransformComponent2D>()) {

		//Print values of component
		std::cout << '\n' << "Transfrorm X: " << transform->position.x;
	}
}