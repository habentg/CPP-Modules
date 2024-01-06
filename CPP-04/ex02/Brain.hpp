/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:10:46 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/05 20:17:22 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
    protected:
        std::string _ideas[100];
    public:
        Brain(void);
        ~Brain(void);
        Brain(Brain const &src);
        Brain& operator=(Brain const &rhs);
};

#endif