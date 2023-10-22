/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:47:17 by mbabela           #+#    #+#             */
/*   Updated: 2023/10/21 21:30:23 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

# include <iostream>
# include <string>

class Computor 
{
    private:
        std::string __secondQ;
        std::string __firstQ;
        std::string __Quo;
        std::string __Res;
        std::string __Discriminent;
        std::string __degree;

    public:
        Computor();
        Computor(std::string );
        Computor(Computor &);
        ~Computor();

        Computor*   operator=(const Computor& );
        friend std::ostream & operator << (std::ostream &out, const Computor& );

        std::string const & getSecond(void);
        std::string const & getFirst(void);
        std::string const & getQou(void);
        std::string const & getRes(void);
        std::string const & getDiscriminent(void);
        std::string const & getDegree(void);

        void        setSecond(std::string);
        void        setFirst(std::string);
        void        setQou(std::string);
        void        setRes(std::string);
        void        setDiscriminet(std::string);
        void        setDegree(std::string);

        int         getPArts(std::string, std::string, int );

        std::string CalculateDiscriminent(std::string, std::string, std::string);

};


#endif