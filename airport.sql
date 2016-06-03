--
-- File generated with SQLiteStudio v3.0.7 on Fri Jun 3 06:46:22 2016
--
-- Text encoding used: windows-1252
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: seat_no
CREATE TABLE seat_no (seat_no INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL);

-- Table: flight
CREATE TABLE flight (flight_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, airport_name STRING (1, 100) NOT NULL REFERENCES airport (airport_name), source STRING (1, 100) NOT NULL, destination STRING (1, 100) NOT NULL, departure TIME NOT NULL, arrival TIME NOT NULL, duration TIME NOT NULL, total_seats INTEGER (1, 1000) NOT NULL, departure_date DATE NOT NULL);
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (1, 'Sarajevo', 'Sarajevo', 'Ljubljana', '10:10:10', '12:00:00', '01:50:00', 50, '2016-05-31');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (2, 'Madrid', 'Madrid', 'Munchen', '12:10:00', '14:00:00', '01:50:00', 60, '2016-05-30');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (3, 'Munchen', 'Munchen', 'Madrid', '15:40:00', '17:40:00', '02:00:00', 70, '2016-05-27');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (4, 'Amsterdam', 'Amsterdam', 'Brisel', '19:00:00', '20:30:00', '01:30:00', 100, '2016-04-20');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (5, 'Moscow', 'Moscow', 'Frakfurt', '12:00:00', '15:00:00', '03:00:00', 150, '2016-04-15');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (6, 'Ljubljana', 'Ljubljana', 'Sarajevo', '10:00:00', '11:30:00', '01:30:00', 200, '2016-04-04');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (7, 'Brisel', 'Brisel', 'Amsterdam', '11:30:00', '13:00:00', '01:30:00', 250, '2016-03-23');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (8, 'Frankfurt', 'Frankfurt', 'Moscow', '10:00:00', '13:00:00', '03:00:00', 300, '2016-03-16');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (9, 'London', 'London', 'Barcelona', '12:00:00', '13:30:00', '01:30:00', 300, '2016-03-06');
INSERT INTO flight (flight_id, airport_name, source, destination, departure, arrival, duration, total_seats, departure_date) VALUES (10, 'Barcelona', 'Barcelona', 'London', '13:00:00', '14:30:00', '01:30:00', 300, '2016-02-20');

-- Table: customer
CREATE TABLE customer (customer_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, username STRING (4, 16) NOT NULL UNIQUE, password STRING (8, 16) NOT NULL, name STRING (1, 25) NOT NULL, last_name STRING (1, 25) NOT NULL, address STRING (1, 100) NOT NULL, phone INTEGER (9, 25) NOT NULL, age INTEGER (1, 120) NOT NULL, ccn_no INTEGER REFERENCES ccn (ccn_no), isLoggedIn INTEGER (0, 1) NOT NULL DEFAULT (0));
INSERT INTO customer (customer_id, username, password, name, last_name, address, phone, age, ccn_no, isLoggedIn) VALUES (1, 'Vikiviki', 12345678, 'Vildan', 'Živojevi?', 'Šukrije Kukavice 43', 37861601946, 21, NULL, '');
INSERT INTO customer (customer_id, username, password, name, last_name, address, phone, age, ccn_no, isLoggedIn) VALUES (2, 'Vildan', 12345678, 'Vildan', 'Zivojevic', 'Hrasnicka 15', 387000003, 21, NULL, 0);
INSERT INTO customer (customer_id, username, password, name, last_name, address, phone, age, ccn_no, isLoggedIn) VALUES (3, 'Mehmed', 'abcd1234', 'Mehmed', 'Jakubovic', 'Hrasnicka 15', 387000002, 21, NULL, 0);
INSERT INTO customer (customer_id, username, password, name, last_name, address, phone, age, ccn_no, isLoggedIn) VALUES (4, 'Bekir', '1234abcd', 'Bekir', 'Bukvarevic', 'Grbavica 1234', 387000001, 21, NULL, 0);
INSERT INTO customer (customer_id, username, password, name, last_name, address, phone, age, ccn_no, isLoggedIn) VALUES (5, 'Halid', '12345abcd', 'Halid', 'Hasic', 'Fincija 05', 387000000, 21, NULL, 0);

-- Table: payment
CREATE TABLE payment (payment_id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, customer_id INTEGER NOT NULL REFERENCES customer (customer_id), flight_id INTEGER REFERENCES flight (flight_id) NOT NULL, ticket_no INTEGER REFERENCES ticket (ticket_no) NOT NULL, price INTEGER (1, 10000) NOT NULL, mode STRING (1, 100) NOT NULL);

-- Table: admin
CREATE TABLE admin (admin_id INTEGER PRIMARY KEY NOT NULL UNIQUE, password STRING (6, 20) NOT NULL, username STRING (6, 20) NOT NULL);

-- Table: airport
CREATE TABLE airport (airport_name STRING (1, 100) PRIMARY KEY NOT NULL);
INSERT INTO airport (airport_name) VALUES ('Sarajevo');
INSERT INTO airport (airport_name) VALUES ('Madrid');
INSERT INTO airport (airport_name) VALUES ('Munchen');
INSERT INTO airport (airport_name) VALUES ('Amsterdam');
INSERT INTO airport (airport_name) VALUES ('Frankfurt');
INSERT INTO airport (airport_name) VALUES ('Moscow');
INSERT INTO airport (airport_name) VALUES ('London');
INSERT INTO airport (airport_name) VALUES ('Barcelona');
INSERT INTO airport (airport_name) VALUES ('Ljubljana');
INSERT INTO airport (airport_name) VALUES ('Brisel');

-- Table: class
CREATE TABLE class (class STRING (1, 29) NOT NULL PRIMARY KEY);
INSERT INTO class (class) VALUES ('Economy');
INSERT INTO class (class) VALUES ('Business');
INSERT INTO class (class) VALUES ('First');

-- Table: typeOfcc
CREATE TABLE typeOfcc (type STRING (1, 30) NOT NULL PRIMARY KEY);
INSERT INTO typeOfcc (type) VALUES ('American Express');
INSERT INTO typeOfcc (type) VALUES ('Visa');
INSERT INTO typeOfcc (type) VALUES ('MasterCard');

-- Table: ticket
CREATE TABLE ticket (ticket_no INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, seat_no INTEGER (1, 150) NOT NULL REFERENCES seat_no (seat_no), customer_id INTEGER REFERENCES customer (customer_id) NOT NULL, flight_id INTEGER REFERENCES flight (flight_id) NOT NULL, source INTEGER REFERENCES flight (source) NOT NULL, destination STRING REFERENCES flight (destination) NOT NULL, departure STRING NOT NULL REFERENCES flight (departure), departure_date STRING REFERENCES flight (departure_date) NOT NULL, class STRING (1, 29) NOT NULL DEFAULT Economy DEFAULT Business DEFAULT First REFERENCES class (class));

-- Table: ccn
CREATE TABLE ccn (ccn_no INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, payment_id INTEGER REFERENCES payment (payment_id) NOT NULL, ticket_no INTEGER NOT NULL REFERENCES ticket (ticket_no), name STRING (1, 100) NOT NULL, verification_number INTEGER (1, 15) NOT NULL, expiry DATETIME NOT NULL, type STRING REFERENCES typeOfcc (type) NOT NULL);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
