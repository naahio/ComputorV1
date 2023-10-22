/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:54:09 by mbabela           #+#    #+#             */
/*   Updated: 2023/10/21 21:44:56 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/Computor.hpp"

Computor::Computor() {}
Computor::Computor(std::string equation) {
    for (int i = 0; i < equation.length(); i++)
    {
        i += getPArts(this->__Quo, equation, i);
        i += getPArts(this->__firstQ, equation, i);
        i += getPArts(this->__secondQ, equation, i);
        i += getPArts(this->__Res, equation, i);
    }
    this->__Discriminent = CalculateDiscriminent(this->__Quo, this->__firstQ, this->__secondQ);
    std::cout << equation << std::endl;
}
Computor::Computor(Computor &obj) {
    *this = obj;
}
Computor::~Computor() {}

Computor* Computor::operator=(const Computor& obj){
    this->__secondQ = obj.__secondQ;
    this->__firstQ = obj.__firstQ;
    this->__Quo = obj.__Quo;
    this->__Discriminent = obj.__Discriminent;
    this->__degree = obj.__degree;
    return this;
}
std::ostream& operator<<(std::ostream &os, Computor& n){
    os << "Reduced form : "<< n.getQou() << " " << std::endl;
    std::cout << "Polynomial degree: " << std::endl;
    std::cout << "Discriminant is : " << std::endl;
    std::cout << "solutions are : " << std::endl;
    return os;
}

std::string const & Computor::getSecond(void){ return this->__secondQ; }
std::string const & Computor::getFirst(void){ return this->__firstQ; }
std::string const & Computor::getQou(void){ return this->__Quo; }
std::string const & Computor::getRes(void){ return this->__Res; }
std::string const & Computor::getDiscriminent(void){ return this->__Discriminent; }
std::string const & Computor::getDegree(void){return this->__degree; }

void        Computor::setSecond(std::string str){this->__secondQ = str; }
void        Computor::setFirst(std::string str){this->__firstQ = str; }
void        Computor::setQou(std::string str){this->__Quo = str; }
void        Computor::setRes(std::string str){this->__Res = str; }
void        Computor::setDiscriminet(std::string str) {this->__Discriminent = str; }
void        Computor::setDegree(std::string str) {this->__degree = str; }
int         Computor::getPArts(std::string attribute, std::string equation, int i)
{
    for (; i < equation.length(); i++)
    {
        
    }
}

std::string Computor::CalculateDiscriminent(std::string qou, std::string first, std::string second) {
    
}