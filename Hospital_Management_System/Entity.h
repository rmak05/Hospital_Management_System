#pragma once

#include <memory>

class Entity;
enum class EntityType;
typedef std::shared_ptr<Entity> entity_ptr;

enum class EntityType {

};

class Entity {
private:
	bool isActive;
	//size_t id;
	EntityType type;

	Entity();
	Entity(const size_t _id, const EntityType _type);

public:

	//bool check_is_active() const;
	//const EntityType get_type() const;
	//const size_t get_id() const;
	// void destroy();
};