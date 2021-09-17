
#include "validation.h"

bool vint::eval(int target)
{
	switch (this->evalType)
	{
	case EVAL_INT_NE:
		return (value != target);
		break;
	case EVAL_INT_EQ:
		return (value == target);
		break;
	case EVAL_INT_GT:
		return (value < target);
		break;
	case EVAL_INT_GE:
		return (value <= target);
		break;
	case EVAL_INT_LT:
		return (value > target);
		break;
	case EVAL_INT_LE:
		return (value >= target);
		break;
	default:
		break;
	}
	return false;
}


vint::vint(evalTypeInt_t evalType, int value)
{
	/* 整数型を比較対象とする場合 evalType は適切なものしか受け付けない */
	this->op = V_AND;
	this->evalType = evalType;
	this->value = value;
}


// コンストラクタ vintのvectorを受け取る
CValidation_Integer::CValidation_Integer(std::vector<vint> vope)
	:vopes(vope)
	,m_value(0)
	,m_ret(0)
{

}


bool CValidation_Integer::operator()(int value)
{
	bool IsFirst = true;
	for (auto& op : vopes)
	{
		if (IsFirst)
		{
			IsFirst = false;
			m_ret = op.eval(value);
		}
		else
		{
			m_ret = (m_ret && op.eval(value));
		}
	}
	return m_ret;
}
