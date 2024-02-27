/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:54:09 by mbabela           #+#    #+#             */
/*   Updated: 2024/02/27 13:20:15 by mbabela          ###   ########.fr       */
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
    this->__degree = 0;
    this->__Discriminent = 0;
}

Computor::Computor(std::string equation) {
    bool foundEqual = false;

   
         for (size_t i = 0; i < equation.length(); i++)
    {if (!foundEqual) {
            if (!foundEqual)
                i += getPArts("__Quo", equation, i, &foundEqual);
            if (!foundEqual)
                i += getPArts("__firstQ", equation, i, &foundEqual);
            if (!foundEqual)
                i += getPArts("__secondQ", equation, i, &foundEqual);
            if (!foundEqual)
                i += getPArts("__thirdQ", equation, i, &foundEqual);
        } else {
            i += getPArts("__QuoF", equation, i, &foundEqual);
            i += getPArts("__firstQF", equation, i, &foundEqual);
            i += getPArts("__secondQF", equation, i, &foundEqual);
            i += getPArts("__thirdQF", equation, i, &foundEqual);
        }
    }
    
    this->__Discriminent = CalculateDiscriminent(this->__Quo, this->__firstQ, this->__secondQ);
    // std::cout << equation << std::endl;
    // std::cout << "Reduced Form : " << this->getReducedForm() << std::endl;
    
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

std::ostream& operator<<(std::ostream& os, const Computor& n) {
    os << "---------------> Solving equation .  <---------------";
    // sleep (1);
    os << ". ";
    sleep (1);
    os << ". " << std::endl;;
    sleep (1);
    os << "Reduced form                 :   "<< n.getReducedForm() << " " << std::endl;
    sleep (1);
    os << "Polynomial degree            :   " << n.getDegree() << std::endl;
    sleep (1);
    os << "Discriminant is b^2 - 4ac    :   " << n.getDiscriminent() << std::endl;
    sleep (1);
    os << "solutions are : > 0 => (-b + (sqrt(dist)))/2a | (-b - (sqrt(disc)))/2a" << n.get  << std::endl;
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

float   Computor::getDiscriminent (void) const { 
    return (this->__Discriminent);
}

float   const & Computor::getReducedFormQuo(void) { return this->reducedFromQuo; }
float   const & Computor::getReducedFormFirstQ(void) { return this->reducedFromFirstQ; }
float   const & Computor::getReducedFormSecondQ(void) { return this->reducedFromSecondQ; };
float   const & Computor::getReducedFormThirst(void) { return this->reducedFromThirdQ; };

int     const & Computor::getDegree (void) const { return this->__degree; }

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

void        Computor::setReducedFormQuo(float Var) { this->reducedFromQuo = Var; }
void        Computor::setReducedFormFirstQ(float Var) { this->reducedFromFirstQ = Var; }
void        Computor::setReducedFormSecondQ(float Var) { this->reducedFromSecondQ = Var; }
void        Computor::setReducedFormThirdQ(float Var) { this->reducedFromThirdQ = Var; }

void        Computor::setDegree (int str) { this->__degree = str; }

size_t      Computor::getPArts(std::string attribute, std::string equation, size_t i, bool *foundEqual)
{
    size_t      len;
    size_t      start;
    std::string result;

    start = 0;
    len = 0;
    if ((i >= equation.length()))
        return (0);
    for (; (i < equation.length()); i++, start++)
    {    
        if (equation[i] == '*')
            break;
        if (equation[i] != ' ')
            result += equation[i];
    }
    if (!attribute.compare("__Quo")) {
        this->__Quo = std::stof(result);
    }
    else if (!attribute.compare("__firstQ")) {
        this->__firstQ = std::stof(result);
    }
    else if (!attribute.compare("__secondQ")){
        this->__secondQ = std::stof(result);
    }
    else if (!attribute.compare("__thirdQ")) {
        this->__thirdQ = std::stof(result);
    }
    else if (!attribute.compare("__QuoF")) {
        this->__QuoF = std::stof(result);
    }
    else if (!attribute.compare("__firstQF")) {
        this->__firstQF = std::stof(result);
    }
    else if (!attribute.compare("__secondQF")) {
        this->__secondQF = std::stof(result);
    }
    else if (!attribute.compare("__thirdQF")) {
        this->__thirdQF = std::stof(result);
    }
    for (; (i < equation.length() && equation[i] != '+' 
        && equation[i] != '-' && equation[i] != '='); i++, start++)
        ;
    if (equation[i] == '=') {
        *foundEqual = true;
        start++;
    }
    return (start);
}

std::string Computor::getReducedForm() const {
    std::string reducedForm = "";
    std::string Quo;
    std::string FirstQ;
    std::string SecondQ;
    std::string ThirdQ;
    std::stringstream ss;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;

    ss << (this->__Quo - this->__QuoF);
    Quo     =   ss.str();
    ss1 << (this->__firstQ - this->__firstQF);
    FirstQ  =   ss1.str();
    ss2 << (this->__secondQ - this->__secondQF);
    SecondQ =   ss2.str(); 
    ss3 << (this->__thirdQ - this->__thirdQF);
    ThirdQ  =   ss3.str(); 
    std::cout << "Third : " << this->__thirdQ << std::endl;
    if (Quo.compare("0")) {
        if ((this->__firstQ + this->__firstQF) > 0)
            Quo += " + ";
        else
            Quo += " ";
        reducedForm += Quo;
    }
    if (FirstQ.compare("0")) {
        if ((this->__secondQ + this->__secondQF) > 0)
            FirstQ += " * X^1 + ";
        else
            FirstQ += " * X^1 ";

        reducedForm += FirstQ;
    }
    if (SecondQ.compare("0")) {
        if ((this->__thirdQ + this->__thirdQF) > 0)
            SecondQ += " * X^2 + ";
        else
            SecondQ += " * X^2 ";
        reducedForm += SecondQ;
    }
    if (ThirdQ.compare("0")) {
        ThirdQ += " * X^3 ";
        reducedForm += ThirdQ;
    }
    reducedForm += " = 0";

    return (reducedForm);
}

float Computor::CalculateDiscriminent(void ) {
   // b^2 - 4ac
    float a = (this->__secondQ - this->__secondQF);
    float b = (this->__firstQ - this->__firstQF);
    float c = (this->__Quo - this->__QuoF);

    float dis = (b * b) - (4 * a * c);
 
    return  dis; 
}

void    split(std::string const &s1, char delim, std::vector<std::string> &out)
{
    std::stringstream X(s1);
    std::string T;

    while (std::getline(X,T,delim))
    {
        if (!T.empty())
            out.push_back(T);
    }
}

int Computor::CalcutlateDegree(std::string equation) {
    std::vector<std::string> breakedEq;
    size_t  found;

    split(equation, '=', breakedEq);

    found = breakedEq[0].find("X^3");
    if (found != std::string::npos)
        return(3);
    found = breakedEq[0].find("X^2");
    if (found != std::string::npos)
        return(2);
    found = breakedEq[0].find("X^1");
    if (found != std::string::npos)
        return(1);
    return (0);
}


std::string Computor::getSolutions() const {
    float a = (this->__secondQ - this->__secondQF);
    float b = (this->__firstQ - this->__firstQF);
    float c = (this->__Quo - this->__QuoF);

    if (this->getDegree() > 2)
        return "The polynomial degree is strictly greater than 2, I can't solve. ";
    if (this->getDiscriminent() < 0) 
        return "Discriminant is strictly positive, the two solutions are: ";

}