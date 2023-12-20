# C Project - Trip PLaner 

This repository contains a C project *The Trip Planner app*, which is a versatile tool designed to simplify the process of planning and organizing trips. Whether you are a service provider registering your hotel or rental car service or a client seeking efficient travel plans, this app caters to your needs.

## About Project


### Features

#### For Service Providers
- **Registration and Login:**
  - Service providers (hotels and rental car services) can register with the app by providing necessary credentials.
  - After registration, providers can log in to manage their rooms and cars by adding or deleting them.

#### For Clients
- **Client Interaction:**
  - Clients can use the app without registration or login.
  - Input trip details, including:
    - **Place:** Destination for the trip.
    - **Budget:** Budget allocated for the trip.
    - **Days:** Number of days planned for the trip.
    - **Rental Car:** Preference for renting a car during the trip (optional).

- **Trip Plans:**
  - The app generates efficient trip plans based on client input, considering budget constraints and the number of days planned.
  - Each plan includes hotel accommodation and, optionally, a rental car based on the client's preference.

- **Custom Plans:**
  - If a client is dissatisfied with the machine-generated plans, they have the option to manually choose their own plans.
  - Clients can browse available hotels and car rentals to create a personalized trip plan that suits their preferences.

- **Booking Process:**
  - If a client chooses a generated plan or creates their own:
    - A trip ticket is generated containing essential details.
    - Hotel rooms are booked.
    - Rental car reservation (optional) is made based on the client's choices.

- **Demo App:**
  - This version of the app is a demo, lacking proper email verification and payment methods for simplicity.


## Contributors

This project is brought to you by the collaborative efforts of:

- **Hassam**
- **Danish**
- **Shahzaib**




## Project Structure

- **main.c**: This file contains the `main` function and serves as the entry point for the program. To start the application, compile and run this file.

- **carRead.c**: The `carRead.c` file contains functions related to reading data from the `cars.dat` file. This is where the program retrieves information about cars stored in the binary file.

- **hotelRead.c**: The `hotelRead.c` file contains functions for reading data from the `hotels.dat` file. This is where the program retrieves information about hotels stored in the binary file.

- **initializer.c**: The `initializer.c` file contains functions to initialize the `hotels.dat` file with empty hotel data.

- **carInitializer.c**: The `carInitializer.c` file contains functions to initialize the `cars.dat` file with empty car data.

- **struct_car.h**: This file contains the structure definition for cars.

- **struct_hotel.h**: This file contains the structure definition for hotels.

- **carPostLogin.h**: This file contains functions related to car management after a user login.

- **hotelPostLogin.h**: This file contains functions related to hotel management after a user login.

- **other files**: There are various other files containing functions specific to their names, such as `carPostLogin.h` and `PostLogin.h`. These files contain functionalities for car and hotel management post-login, respectively.


## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Muhammad-Shah-zaib/cproject
   cd cproject

