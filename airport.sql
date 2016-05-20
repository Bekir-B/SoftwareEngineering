--
-- File generated with SQLiteStudio v3.0.7 on pet maj 20 15:56:40 2016
--
-- Text encoding used: windows-1250
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: flight
CREATE TABLE flight (flight_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, airport_name STRING (1, 100) NOT NULL REFERENCES airport (airport_name), source STRING (1, 100) NOT NULL, destination STRING (1, 100) NOT NULL, departure TIME NOT NULL, arrival TIME NOT NULL, duration TIME NOT NULL, total_seats INTEGER (1, 1000) NOT NULL);

-- Table: airport
CREATE TABLE airport (airport_name STRING (1, 100) PRIMARY KEY NOT NULL, address STRING (1, 100) NOT NULL, airlines STRING (1, 100) NOT NULL, schedules DATETIME NOT NULL, parking BIGINT (1, 1000) NOT NULL, facilities STRING (1, 100) NOT NULL, baggage STRING (1, 100) NOT NULL, services STRING (1, 100) NOT NULL);

-- Table: ticket
CREATE TABLE ticket (ticket_no INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, customer_id INTEGER REFERENCES customer (customer_id) NOT NULL, flight_id INTEGER REFERENCES flight (flight_id) NOT NULL, source STRING NOT NULL, destination STRING NOT NULL, departure STRING NOT NULL, seat_no INTEGER NOT NULL, price INTEGER (1, 10000) NOT NULL, name STRING (1, 100) NOT NULL);

-- Table: ccn
CREATE TABLE ccn (ccn_no INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, payment_id INTEGER REFERENCES customer NOT NULL, ticket_no INTEGER REFERENCES flight NOT NULL, name STRING (1, 100) NOT NULL, bank STRING (1, 100) NOT NULL, expiry DATETIME NOT NULL);

-- Table: staff
CREATE TABLE staff (staff_id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, first_name STRING (1, 100) NOT NULL, last_name STRING (1, 100) NOT NULL, position STRING (1, 100) NOT NULL, role STRING (1, 100) NOT NULL, address STRING (1, 100) NOT NULL, phone INTEGER (1, 50) NOT NULL, mail STRING (1, 100) NOT NULL);

-- Table: customer
CREATE TABLE customer (name STRING (1, 100) NOT NULL, last_name STRING (1, 100) NOT NULL, address STRING (1, 100) NOT NULL, phone INTEGER (1, 50) NOT NULL, age INTEGER (1, 120) NOT NULL, customer_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, ccn_no INTEGER REFERENCES "sqlitestudio_temp_table1" (ccn_no));
INSERT INTO customer (name, last_name, address, phone, age, customer_id, ccn_no) VALUES ('pf2g', 'dm8mz', '
ii1ricbsc7r8', 490, 31499, 1, NULL);
INSERT INTO customer (name, last_name, address, phone, age, customer_id, ccn_no) VALUES ('duujge3g', '2q08bkhffias', 'vlc82p', 18813, 28971, 2, NULL);

-- Table: payment
CREATE TABLE payment (payment_id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE NOT NULL, customer_id INTEGER REFERENCES customer (customer_id) NOT NULL, flight_id INTEGER REFERENCES flight (flight_id) NOT NULL, ticket_no INTEGER REFERENCES ticket (ticket_no) NOT NULL, price INTEGER (1, 10000) NOT NULL, mode STRING (1, 100) NOT NULL);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
