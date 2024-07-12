/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:34:33 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/10 14:48:03 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main() {
    int n = 10;
    pthread_mutex_t *mutexes;
    mutexes = (pthread_mutex_t *)malloc(n * sizeof(pthread_mutex_t));
    if (mutexes == NULL) {
        perror("Failed to allocate memory for mutexes");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (pthread_mutex_init(&mutexes[i], NULL) != 0) {
            perror("Failed to initialize mutex");
            free(mutexes);
            return 1;
        }
    }
    //for (int i = 0; i < n; i++) {
    //    pthread_mutex_destroy(&mutexes[i]);
    //}
    //free(mutexes);
    return 0;
}