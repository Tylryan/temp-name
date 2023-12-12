#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "./lexer.h"

enum P_TYPE
{
	PARSER_INTERFACE,
	PARSER_KLASS,
	PARSER_METHOD,
	PARSER_ARROW,
	PARSER_FIELD,
	PARSER_PACKAGE
};

struct klass
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
	std::string value;
	std::string package;
};

struct inter
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
	std::string value;
	std::string package;
};

struct package
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
	std::string value;
};

struct field
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
	std::string value;
};

struct method
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
	std::string value;
};

struct arrow
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
	std::string source_id;
	std::string target_id;
};


struct common
{
	enum P_TYPE type;
	std::string id;
	std::string pid;
};

union p_object
{
	struct common * common;
	struct klass  * klass;
	struct field  * field;
	struct method * method;
	struct arrow  * arrow;
	struct inter  * inter;
	struct package * package;
};

struct parser
{
	size_t current;
	bool has_packages;
	std::vector<union p_object> parser_objects;
	std::vector<struct token*> tokens;
};

struct parser parser_create(std::vector<struct token*> tokens, bool has_packages);
std::vector<struct klass>
parser_parse(struct parser * self);    

std::string p_object_to_str(union p_object * po);