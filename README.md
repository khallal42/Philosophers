# Philosophers

## Overview
Philosophers is a project assigned as part of the curriculum at 1337 school, addressing the classic Dining Philosophers Problem. This project aims to explore concurrent programming, synchronization challenges, and presents two solutions: one using threads and another using processes with semaphores as a bonus.

## Introduction
The Philosophers project delves into the intricate world of concurrent programming by addressing the Dining Philosophers Problem. Philosophers, represented as entities, must find an optimal way to share resources (e.g., forks) without conflicts, avoiding deadlock or resource contention.

## Philosophers Problem
The Dining Philosophers Problem is a classic synchronization and concurrency problem where a group of philosophers sit around a dining table. The challenge lies in preventing conflicts as philosophers alternate between thinking and eating. Resources, such as forks, are shared, and strict rules must be followed to avoid deadlock or starvation.

## Thread Implementation
The primary solution involves utilizing threads to represent each philosopher. Synchronization is achieved through mutexes to control access to shared resources. This solution carefully manages the interaction between philosophers to ensure efficient communication and resource sharing.

## Bonus: Process Implementation with Semaphores
As a bonus, an alternative solution is provided using processes and semaphores. This variation explores the use of inter-process communication mechanisms to address the Dining Philosophers Problem. Semaphores play a crucial role in coordinating access to shared resources among processes.

## Usage
1. Clone the repository: `git@github.com:khallal42/Philosophers.git`
2. Navigate to the project directory: `cd philosophers`
3. Build the project: `make`
4. Run the program with appropriate arguments: `./philo (|| philo_bonus for run bonus part) [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_to_eat]`

## Contributing
Contributions are welcome! If you have suggestions for improvements or find any issues, feel free to open an issue or submit a pull request.
