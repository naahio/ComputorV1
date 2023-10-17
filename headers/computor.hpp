/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:47:17 by mbabela           #+#    #+#             */
/*   Updated: 2023/10/13 23:28:35 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

# include <iostream>
# include <string>

class Computor 
{
    private:
        std::string R_secondQ;
        std::string R_firstQ;
        std::string R_Quo;
        std::string L_secondQ;
        std::string L_firstQ;
        std::string L_Quo;
    public:
        Computor();
        Computor(std::string );
        Computor(Computor &);
        ~Computor();

        Computor*   operator=(const Computor& );

};



#endif