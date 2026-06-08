# CampusBite Pre-Order Food System

## Overview

CampusBite is a web-based food pre-ordering system designed for campus environments. The system allows students to browse food menus, place pre-orders, and receive order status updates. Merchants can manage food items and process orders, while administrators oversee users and system reports.

---

## Features

### Student Features

* User registration and login
* Browse available merchants
* View food menus
* Add food items to cart
* Place pre-orders
* Track order status
* Receive notifications for order updates
* Manage profile and profile image
* Reset password

### Merchant Features

* Merchant registration
* Manage food items

  * Add food
  * Edit food
  * Remove food
* View incoming orders
* Update order status
* Generate daily reports
* Manage shop information

### Administrator Features

* Manage users
* Add new users
* Edit user information
* View system reports
* Monitor platform activities

---

## Technology Stack

### Backend

* Node.js
* Express.js
* MongoDB
* Mongoose

### Frontend

* EJS Template Engine
* HTML5
* CSS3
* JavaScript

### Authentication & Security

* Express Session
* bcryptjs Password Hashing
* Role-Based Access Control

### File Storage

* MongoDB GridFS
* Multer

### Deployment

* Vercel

---

## Project Structure

```text
CampusBitePre-OrderFoodSystem/
│
├── api/
│   └── index.js
│
├── config/
│   ├── db.js
│   └── mediaStore.js
│
├── middleware/
│   ├── authMiddleware.js
│   ├── roleMiddleware.js
│   └── uploadMiddleware.js
│
├── models/
│   ├── User.js
│   ├── FoodItem.js
│   └── Order.js
│
├── public/
│   ├── css/
│   └── js/
│
├── routes/
│   ├── authRoutes.js
│   ├── foodRoutes.js
│   ├── homeRoutes.js
│   ├── mediaRoutes.js
│   ├── menuRoute.js
│   ├── orderRoutes.js
│   ├── shopRoutes.js
│   └── userRoutes.js
│
├── scripts/
│   ├── createAdmin.js
│   ├── generateDummyMerchants.js
│   └── migrateUploadsToImages.js
│
├── views/
│   ├── admin/
│   ├── auth/
│   ├── customer/
│   ├── merchant/
│   └── orders/
│
├── app.js
├── server.js
├── package.json
└── vercel.json
```

---

## Database Models

### User

| Field        | Type                       |
| ------------ | -------------------------- |
| username     | String                     |
| email        | String                     |
| password     | String                     |
| role         | student / merchant / admin |
| merchantType | String                     |
| profileImage | String                     |
| createdAt    | Date                       |

---

### FoodItem

| Field        | Type       |
| ------------ | ---------- |
| name         | String     |
| price        | Decimal128 |
| category     | String     |
| description  | String     |
| availability | Boolean    |
| image        | String     |
| merchant     | ObjectId   |

---

### Order

| Field           | Type       |
| --------------- | ---------- |
| student         | ObjectId   |
| merchant        | ObjectId   |
| items           | Array      |
| totalPrice      | Decimal128 |
| fulfillmentType | String     |
| paymentMethod   | String     |
| status          | String     |
| createdAt       | Date       |
| remark          | String     |

---

## Installation

### 1. Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git
cd CampusBitePre-OrderFoodSystem
```

### 2. Install Dependencies

```bash
npm install
```

### 3. Configure Environment Variables

Create a `.env` file:

```env
PORT=3000
MONGO_URI=your_mongodb_connection_string
SESSION_SECRET=your_session_secret
NODE_ENV=development
```

### 4. Run Development Server

```bash
npm run dev
```

### 5. Run Production Server

```bash
npm start
```

---

## User Roles

### Student

* Browse restaurants
* Place orders
* Track orders
* Manage account

### Merchant

* Manage menu items
* Process orders
* View reports

### Admin

* Manage users
* Generate reports
* Monitor platform activities

---

## Security Features

* Password hashing using bcryptjs
* Session-based authentication
* Role-based authorization
* Protected routes
* Input validation
* File upload restrictions
* Secure cookie configuration

---

## Notifications

The system includes:

* Order status notifications
* Merchant order alerts
* Toast message system
* Real-time order polling

---

## Deployment

The application supports deployment on Vercel.

Configuration is handled through:

```text
vercel.json
```

Key deployment features:

* Serverless Express support
* MongoDB connection caching
* Static asset routing
* GridFS media storage


## Authors

Developed as part of an academic project for a Campus Food Pre-Ordering System.
* ```Project Supervisor - Mr. Muhammad Mahfuz bin Zainuddin```
* Scrum Master - Wong Jing Xuan
* Yyl06 - Originally known as Yong Yuan Lin
* Tester - Tey Shu Ying 
* and some random friends from Yyl06, Special thanks for testing

## License

This project is intended for educational purposes.
