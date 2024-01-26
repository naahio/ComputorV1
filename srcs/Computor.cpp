/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:54:09 by mbabela           #+#    #+#             */
/*   Updated: 2024/01/26 15:51:15 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/Computor.hpp"

Computor::Computor() {
    this->__thirdQ = 0;
    this->__secondQ = 0;
    this->__firstQ = 0;
    this->__QuoF = 0;
    this->__thirdQF = 0;
    this->__secondQF = 0;
    this->__firstQF = 0;
    this->__Quo = 0;
    this->__Discriminent = 0;
    this->__degree = 0;
    // this->__Res = 0;
}

Computor::Computor(std::string equation) {
    std::cout << "length : " << equation.length() << std::endl;
    for (size_t i = 0; i < equation.length(); i++)
    {
        i += getPArts("__Quo", equation, i);
            std::cout << "--> __Quo : " << this->__Quo << std::endl;
        i += getPArts("__firstQ", equation, i);
            std::cout << "--> __firstQ : " << this->__firstQ << std::endl;
        i += getPArts("__secondQ", equation, i);
            std::cout << "--> __secondQ : " << this->__secondQ <<  std::endl;
        i += getPArts("__thirdQ", equation, i);
            std::cout << "--> __thirdQ : " << this->__thirdQ <<  std::endl;
        i += getPArts("__QuoF", equation, i);
            std::cout << "--> __QuoF : " << this->__QuoF << std::endl;
        i += getPArts("__firstQF", equation, i);
            std::cout << "--> __firstQF : " << this->__firstQF << std::endl;
        i += getPArts("__secondQF", equation, i);
            std::cout << "--> __secondQF : " << this->__secondQF <<  std::endl;
        i += getPArts("__thirdQF ", equation, i);
            std::cout << "--> __thirdQF : " << this->__thirdQF <<  std::endl;
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
    std::cout << "Discriminant is b^2 - 4ac: " << std::endl;
    std::cout << "solutions are : > 0 => (sqrt(disc))/2 | (sqrt(disc))/2" << std::endl;
    return os;
}

float   const & Computor::getThird (void) { return this->__thirdQ; }
float   const & Computor::getSecond (void) { return this->__secondQ; }
float   const & Computor::getFirst (void) { return this->__firstQ; }
float   const & Computor::getQou (void) { return this->__Quo; }
float   const & Computor::getThirdF (void) { return this->__thirdQ; }
float   const & Computor::getSecondF (void) { return this->__secondQF; }
float   const & Computor::getFirstF (void) { return this->__firstQF; }
float   const & Computor::getQouF (void) { return this->__QuoF; }
float   const & Computor::getRes (void) { return this->__Res; }
float   const & Computor::getDiscriminent (void) { return this->__Discriminent; }
int     const & Computor::getDegree (void) { return this->__degree; }

void        Computor::setThird (float str) { this->__thirdQ = str; }
void        Computor::setSecond (float str) { this->__secondQ = str; }
void        Computor::setFirst (float str) { this->__firstQ = str; }
void        Computor::setQou (float str) { this->__Quo = str; }
void        Computor::setThirdF (float str) { this->__thirdQ = str; }
void        Computor::setSecondF (float str) { this->__secondQF = str; }
void        Computor::setFirstF (float str) { this->__firstQF = str; }
void        Computor::setQouF (float str) { this->__QuoF = str; }
void        Computor::setRes (float str) { this->__Res = str; }
void        Computor::setDiscriminet (float str) { this->__Discriminent = str; }
void        Computor::setDegree (int str) { this->__degree = str; }

size_t      Computor::getPArts(std::string attribute, std::string equation, size_t i)
{
    size_t      len;
    size_t      start;
    std::string result;

    start = 0;
    len = 0;
    std::cout << "-------------- Round : " << i  << " ----------------" << std::endl;
    if (!(i < equation.length()))
        return (0);
    for (; (i < equation.length()); i++, start++)
    {    
        if (equation[i] == '*')
            break;
        if (equation[i] != ' ')
            result += equation[i];
    }
    // std::cout << "--------> result : ["<< result <<"]  | " << attribute << std::endl;
    if (!attribute.compare("__Quo"))
        this->__Quo = std::stof(result);
    else if (!attribute.compare("__firstQ"))
        this->__firstQ = std::stof(result);
    else if (!attribute.compare("__secondQ"))
        this->__secondQ = std::stof(result);
    else if (!attribute.compare("__thirdQ"))
        this->__secondQ = std::stof(result);
    if (!attribute.compare("__QuoF"))
        this->__QuoF = std::stof(result);
    else if (!attribute.compare("__firstQF"))
        this->__firstQF = std::stof(result);
    else if (!attribute.compare("__secondQF"))
        this->__secondQF = std::stof(result);
    // else if (!attribute.compare("__Res"))
    //     this->__Res = std::stof(result);
    for (; (i < equation.length() && equation[i] != '+' 
        && equation[i] != '-' && equation[i] != '='); i++, start++)
        ;
    if (equation[i] == '=')
        start++;
    // std::cout << "=====>>>>> skipping : " << equation[i] << std::endl;
    return (start);
}

float Computor::CalculateDiscriminent(float qou, float first, float second) {
    (void)qou;
    (void)first;
    return (second);
}