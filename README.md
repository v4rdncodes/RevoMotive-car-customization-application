# RevoMotive - Ultimate Car Customization Hub

Welcome to **RevoMotive**, an interactive console-based C++ application that allows users to customize their dream car online with various features including appointment booking, vehicle selection, customization, billing, financing, and feedback!

---

## Features

- **Welcome & Exit Messages**  
  Friendly greeting and thank you notes for a smooth user experience.

- **Online Appointment Booking**  
  Schedule a pickup appointment within 2 months with date/time validation.

- **Customer Details Collection & Editing**  
  Input customer name, mobile number, vehicle usage duration, and pickup location with the ability to update details.

- **Vehicle Selection**  
  Choose from popular car brands (Tesla, BMW, Audi, Mercedes, Toyota, Ford, Honda, Nissan) and their respective models.

- **Detailed Customization Options**  
  Customize:
  - Exterior Color (with price)
  - Tyres (types and costs)
  - Interior (various materials)
  - Framework upgrades (lightweight, reinforced, off-road)
  - Performance upgrades (turbocharge, nitrous, supercharger)
  - Add-ons (sunroof, GPS, rear camera, premium sound system)

- **Bill Calculation & Promo Code Discounts**  
  Calculate total cost including delivery charges and optionally apply promo codes such as `DIWALI10` for a 10% discount.

- **Financing Options**  
  Choose between 3 or 6 months EMI plans (with interest) or full payment.

- **Payment Processing**  
  Supports card (with basic card number validation), UPI, and cash on delivery.

- **Order Summary & Pickup Information**  
  Display a comprehensive summary of customization, billing, and pickup schedule.

- **Feedback System**  
  Rate your experience (1-5 stars) with tailored responses.

---

## Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`, MSVC).
- Command-line interface to run the compiled executable.

### Compilation

### Running the Application

Follow on-screen instructions to:

- Book an appointment
- Enter your details
- Select your car brand and model
- Customize the vehicle
- Review and edit your choices
- Apply promo codes and select payment options
- Provide feedback before exit

---

## Code Structure

- `welcomeMessage()`, `exitMessage()`, `goodbyeMessage()` — Console messages.
- `Booking` — Handles appointment booking with date/time validation.
- `Customer` — Holds customer personal details and editing features.
- `Model` — Manages car brand and model selection.
- `Customization` — Handles vehicle customization and billing of upgrades.
- `Billing` — Calculates final bill, applies discounts, and payment choices.
- `Financing` — Offers EMI and payment plan options.
- `main()` — Orchestrates the user flow.

---

## Validation and Constraints

- **Date Input**: Must be in `DD/MM/YYYY` format and within next 2 months from current date.
- **Time Input**: `HH:MM` format in 24-hour time, validated for correctness.
- **Mobile Number**: Minimum 10 digits.
- **Promo code**: Currently accepts `DIWALI10` for 10% off.
- **Payment Card Number**: Must be exactly 16 digits.

---

## Future Improvements

- GUI frontend for better user interaction.
- Persistent customer data storage and order tracking.
- Expanded range of vehicles and customization options.
- Integration with real payment gateways.
- Web or mobile application version.

---

## License

This project is open source for educational and demonstration purposes.

---

## Contact

For suggestions, issues, or collaborations, please open an issue on this GitHub repository or contact the maintainer.

---

Enjoy customizing your car with **RevoMotive**! 🚗✨
