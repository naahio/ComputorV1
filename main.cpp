/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:45:18 by mbabela           #+#    #+#             */
/*   Updated: 2024/02/27 10:58:35 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/Computor.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "no equation provided" << std::endl;
        return 0;
    }
    Computor *eq = new Computor(av[1]);
    eq->setDegree(eq->CalcutlateDegree(av[1]));
    std::cout << *eq << std::endl;
    // std::cout << "Polynomial degree: " << eq->getDegree() << std::endl;
    delete eq;
}