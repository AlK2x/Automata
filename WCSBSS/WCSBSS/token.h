#pragma once
#include <string>
#include <map>

enum class TokenType
{
	Ilegal,
	Eof,
	Comment,

	Return,
	Var,
	Type,
	Func,
	If,
	For,
	Else,
	Break,
	Continue,
	IntKeyword,
	FloatKeyword,
	StringKeyword,

	Identifier,
	Int,
	Float,
	String,

	Add,      // +
	Sub,      // -
	Mul,      // *
	Assign,   // =
	Equal,    // == 

	LParen,   // (
	Rparen,   // )
	LBracket, // [
	RBracket, // ]
	LBrace,   // {
	RBrace,   // }

	Semicolon, // ;
	Dot,       // .
	Comma      // ,
};

struct Token 
{
	TokenType type;
	std::string tok;
	size_t line;
	size_t row;
};

static std::map<std::string, TokenType> keywords
{
	{"return", TokenType::Return},
	{"var", TokenType::Var},
	{"type", TokenType::Type},
	{"func", TokenType::Func},
	{"if", TokenType::If},
	{"for", TokenType::For},
	{"else", TokenType::Else},
	{"break", TokenType::Break},
	{"continue", TokenType::Continue},
	{"int", TokenType::IntKeyword},
	{"float", TokenType::FloatKeyword},
	{"string", TokenType::StringKeyword}
};