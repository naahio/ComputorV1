/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:47:17 by mbabela           #+#    #+#             */
/*   Updated: 2024/02/27 13:13:39 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

# include <iostream>
# include <string>
# include <vector>  
# include <sstream>
# include <cmath>
# include <iomanip>
# include <sstream>
# include <unistd.h>

class Computor 
{
    private:
        float __thirdQ;
        float __secondQ;
        float __firstQ;
        float __Quo;
        float __thirdQF;
        float __secondQF;
        float __firstQF;
        float __QuoF;
        float __Res;
        float __Discriminent;

        int __degree;

        float   reducedFromQuo;
        float   reducedFromFirstQ;
        float   reducedFromSecondQ;
        float   reducedFromThirdQ;

    public:
        Computor();
        Computor(std::string );
        Computor(Computor &);
        ~Computor();

        Computor*               operator=(const Computor& );

        float       const & getThird (void);
        float       const & getSecond (void);
        float       const & getFirst (void);
        float       const & getQou (void);
        float       const & getThirdF (void);
        float       const & getSecondF (void);
        float       const & getFirstF (void);
        float       const & getQouF (void);
        float       const & getRes (void);

        float       getDiscriminent (void) const;

        float       const & getReducedFormQuo(void);
        float       const & getReducedFormFirstQ(void);
        float       const & getReducedFormSecondQ(void);
        float       const & getReducedFormThirst(void);

        int         const & getDegree (void) const ;

        void        setThird (float);
        void        setSecond (float);
        void        setFirst (float);
        void        setQou (float);
        void        setThirdF (float);
        void        setSecondF (float);
        void        setFirstF (float);
        void        setQouF (float);
        void        setRes (float);
        
        void        setDiscriminet (float);

        void        setReducedFormQuo(float );
        void        setReducedFormFirstQ(float );
        void        setReducedFormSecondQ(float );
        void        setReducedFormThirdQ(float );

        void        setDegree (int);

        size_t      getPArts (std::string, std::string, size_t , bool *);

        float       CalculateDiscriminent (void );

        int         CalcutlateDegree(std::string );

        std::string getReducedForm(void ) const;
        std::string getSolutions(void ) const;
};

std::ostream& operator<<(std::ostream& os, const Computor& n);
void    split(std::string const &, char , std::vector<std::string> &);


#endif