# Hospital Management System

## Overview

The Hospital Management System is a simple C++ console application that allows for the management of a hospital's day-to-day operations. This system enables users to manage patients, doctors, nurses, appointments, and inventory items. The program is designed to be user-friendly and utilizes file handling to store and retrieve data persistently.

## Features

- **Patient Management**
  - Add new patients with details like name, age, gender, address, disease, and admission date.
  - Display all saved patients.

- **Doctor Management**
  - Add new doctors with details like name, age, gender, address, designation, salary, specialization, and availability.
  - Display all saved doctors.

- **Nurse Management**
  - Add new nurses with details like name, age, gender, address, designation, salary, shift, and experience.
  - Display all saved nurses.

- **Appointment Management**
  - Schedule new appointments with details like appointment ID, patient ID, doctor ID, date, and time.
  - Display all saved appointments.

- **Inventory Management**
  - Add new inventory items with details like item ID, item name, quantity, and price.
  - Display all saved inventory items.

## Requirements

- A C++ compiler (e.g., g++, MSVC)
- Basic understanding of C++ concepts such as classes, inheritance, and file handling.


File Structure

hospital-management-system/
├── main.cpp
├── patients.txt
├── doctors.txt
├── nurses.txt
├── appointments.txt
├── inventory.txt
└── README.md
