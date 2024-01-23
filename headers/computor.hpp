/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:47:17 by mbabela           #+#    #+#             */
/*   Updated: 2024/01/23 13:45:02 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

# include <iostream>
# include <string>

class Computor 
{
    private:
        float __secondQ;
        float __firstQ;
        float __Quo;
        float __secondQF;
        float __firstQF;
        float __QuoF;
        float __Res;
        float __Discriminent;
        int __degree;

    public:
        Computor();
        Computor(std::string );
        Computor(Computor &);
        ~Computor();

        Computor*               operator=(const Computor& );
        friend std::ostream &   operator << (std::ostream &out, const Computor& );

        float       const & getSecond (void);
        float       const & getFirst (void);
        float       const & getQou (void);
        float       const & getSecondF (void);
        float       const & getFirstF (void);
        float       const & getQouF (void);
        float       const & getRes (void);
        float       const & getDiscriminent (void);
        int         const & getDegree (void);

        void        setSecond (float);
        void        setFirst (float);
        void        setQou (float);
        void        setSecondF (float);
        void        setFirstF (float);
        void        setQouF (float);
        void        setRes (float);
        void        setDiscriminet (float);
        void        setDegree (int);

        size_t      getPArts (std::string, std::string, size_t );

        float       CalculateDiscriminent (float, float, float);

};


#endif