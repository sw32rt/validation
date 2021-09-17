#pragma once
#include <string>
#include <vector>

enum op_t
{
	V_OR,
	V_AND,
};

enum evalTypeInt_t
{
	EVAL_INT_NE,
	EVAL_INT_EQ,
	EVAL_INT_GT,
	EVAL_INT_GE,
	EVAL_INT_LT,
	EVAL_INT_LE,
};

enum evalTypeStr_t
{
	EVAL_STR_NUMELIC_ONLY,
	EVAL_STR_LEN_EQ,
	EVAL_STR_LEN_NE,
	EVAL_STR_LEN_GT,
	EVAL_STR_LEN_GE,
	EVAL_STR_LEN_LT,
	EVAL_STR_LEN_LE,
	EVAL_STR_MATCH,
	EVAL_STR_UNMATCH,
	EVAL_STR_FOUND,
};

//class voperand_base
//{
//	virtual bool eval(int target) = 0;
//};

class vint
{
public:
	bool eval(int target);
	vint(evalTypeInt_t evalType, int value);

protected:
	op_t op;
	evalTypeInt_t evalType;
	int value;
};

class CValidation_Integer
{
public:
	CValidation_Integer(std::vector<vint> vope);
	bool operator()(int value);

private:
	std::vector<vint> vopes;
	int m_value; // ï]âøëŒè€
	bool m_ret = 0; // èåèââéZåãâ 

};
