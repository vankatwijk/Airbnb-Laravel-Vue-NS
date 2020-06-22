# Project Title

AirBnb Mobile app 
# Project Description

AirBnb clone created using nativescript-vue and laravel as a backend api server(found in the parent directory).

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

Make sure to have node, npm and android development enviroment installed on your local computer to run the code


### Installing


After you clone this project, do the following:

```bash
# install nativescript /tns globally
npm install -g nativescript@latest

# install npm dependencies
npm install / tns install
```

## Debuging
```bash
# if you have problems with your andoid development enviroment, check you SDK paths
export ANDROID_HOME=~/Android/Sdk
export PATH=$PATH:$JAVA_HOME/bin:$ANDROID_HOME/platform-tools:$ANDROID_HOME/tools

OR

export ANDROID_HOME=$HOME/Android/Sdkexport PATH=$PATH:$ANDROID_HOME/tools

```

## Running the tests
```bash
# nativescript live demo
tns run android

```
## API endpoints
```bash
# API documentation
import the postman api collection documentation to view the different endpoints for the project from the parent directory laravelbnb
```

## Built With

* [Laravel](https://laravel.com/) - PHP framework
* [vue.js](https://vuejs.org/) - Javascript frontend framework
* [vue router](https://router.vuejs.org/) - routing between vue components
* [vuex](https://vuex.vuejs.org) - Used to manage the state between components
* [nativescript](https://nativescript.org) - Used to create mobile apps for IOS and Android

## Authors

* **Hendrikus van Katwijk** - [Github](https://github.com/vankatwijk) - [Personal website](https://hpvk.com)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
