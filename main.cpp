/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:45:18 by mbabela           #+#    #+#             */
/*   Updated: 2023/11/12 01:27:17 by mbabela          ###   ########.fr       */
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
    std::cout << eq << std::endl;
}