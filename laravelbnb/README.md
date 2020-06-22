# Project Title

AirBnb web interface created with laravel 7 and vue
# Project Description

AirBnb clone created using laravel and vue.js(vue router , vuex) as a framework. Mysql is used as the backend API database of choose.

## Features
```
Add a property
Create a booking
Create a review
Check for availability
```

## Getting Started

The instructions below will help you setup the copy of the web interface on your development machine.

### Prerequisites

Make sure to have composer and npm installed on your local computer to run the code

Copy the .env.example file into .env

### Installing


After you clone this project, do the following:

```bash
# go into the project
cd laravelbnb

# create a .env file
cp .env.example .env

# install composer dependencies
composer install

# install npm dependencies
npm install

# generate a key for your application
php artisan key:generate

# create a local MySQL database (make sure you have MySQL up and running)
mysql -u root

> create database laravelbnb;
> exit;

# add the database connection config to your .env file
DB_CONNECTION=mysql
DB_DATABASE=laravelbnb
DB_USERNAME=root
DB_PASSWORD=

# run the migration files to generate the schema
php artisan migrate:fresh

# seed your databse with some users and messages
php artisan db:seed

# run webpack and watch for changes
npm run watch
```

## Debuging
```bash
# if you encounter issues
php artisan cache:clear
php artisan config:clear

#for permission issues 
chmod -R 775 /path/to/your/project
```

## Running the tests
```bash
# laravel backend api
php artisan serve / sudo php artisan serve --host 192.168.0.51 --port 9723

# vue.js frontend application
npm run serve (not needed if 'npm run watch' is running)

```
## API endpoints
```bash
# API documentation
import the postman api collection documentation to view the different endpoints for the project
```

## Built With

* [Laravel](https://laravel.com/) - PHP framework
* [vue.js](https://vuejs.org/) - Javascript frontend framework
* [vue router](https://router.vuejs.org/) - routing between vue components
* [vuex](ttps://vuex.vuejs.org) - Used to manage the state between components

## Authors

* **Hendrikus van Katwijk** - [Github](https://github.com/vankatwijk) - [Personal website](https://hpvk.com)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
