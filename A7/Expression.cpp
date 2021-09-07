#include"Expression.h"
#include<iostream>
using calc::ExpPtr;

calc::Literal_::Literal_(double num)
	:num_(num)
{
}
double calc::Literal_::evaluate() const
{
	return num_;
}
calc::ExpPtr calc::Expression::Literal(double d)
{
	ExpPtr newLiteral_ (new Literal_(d));
	return newLiteral_;
}

calc::BinaryOperation::BinaryOperation(ExpPtr lhs, ExpPtr rhs)
	:lhs_(std::move(lhs)), rhs_(std::move(rhs))
{
}

calc::Add_::Add_(ExpPtr lhs_, ExpPtr rhs_)
	:BinaryOperation((std::move(lhs_)),(std::move(rhs_)))
{
}

double calc::Add_::evaluate() const
{
	return (lhs_->evaluate() + rhs_->evaluate());
}
ExpPtr calc::BinaryOperation::Add(ExpPtr lhs, ExpPtr rhs)
{
	ExpPtr A(new Add_(std::move(lhs),std::move(rhs)));
	return A; 
}
calc::Subtract_::Subtract_(ExpPtr lhs_, ExpPtr rhs_)
	:BinaryOperation((std::move(lhs_)),(std::move(rhs_)))
{
}

double calc::Subtract_::evaluate() const
{
	return (lhs_->evaluate() - rhs_->evaluate());
}
ExpPtr calc::BinaryOperation::Subtract(ExpPtr lhs, ExpPtr rhs)
{
	ExpPtr S(new Subtract_(std::move(lhs),std::move(rhs)));
	return S;
}
calc::Multiply_::Multiply_(ExpPtr lhs_, ExpPtr rhs_)
        :BinaryOperation((std::move(lhs_)),(std::move(rhs_)))
{
}

double calc::Multiply_::evaluate() const
{
        return (lhs_->evaluate() * rhs_->evaluate());
}

ExpPtr calc::BinaryOperation::Multiply(ExpPtr lhs, ExpPtr rhs)
{
	ExpPtr M(new Multiply_(std::move(lhs),std::move(rhs)));
	return M;
}
calc::Divide_::Divide_(ExpPtr lhs_, ExpPtr rhs_)
        :BinaryOperation((std::move(lhs_)),(std::move(rhs_)))
{
}

double calc::Divide_::evaluate() const
{
        return (lhs_->evaluate() / rhs_->evaluate());
}

ExpPtr calc::BinaryOperation::Divide(ExpPtr lhs, ExpPtr rhs)
{
	ExpPtr D(new Divide_(std::move(lhs),std::move(rhs)));
	return D;
}
