# ContactTo
This is a contact manager application that allows you to store and manage contacts in a PostgreSQL database.

### Features
- Store contact details like first name, last name, phone numbers, email, company etc.
- View a list of all Contacts

  ![Screenshot 2024-05-02 173721](https://github.com/iAttaquer/ContactTo/assets/145159480/4e9d473e-b657-4bdf-883b-a4a4c587985a)

- View full details of a contact

  ![Screenshot 2024-05-02 173858](https://github.com/iAttaquer/ContactTo/assets/145159480/547a5150-bb5f-41eb-8b2c-707b92447a5b)

- Add new contacts

  ![Screenshot 2024-05-02 173821](https://github.com/iAttaquer/ContactTo/assets/145159480/9482c15d-c4ed-4e32-8f4c-ce9d93e2d770)

- Update existing contacts

  ![Screenshot 2024-05-02 173913](https://github.com/iAttaquer/ContactTo/assets/145159480/1df9562b-a5e5-4f92-8e7c-b7decced42e7)

- Delete contacts

- Mark contacts as favourites

- View list of favourite contacts

  ![Screenshot 2024-05-04 190158](https://github.com/iAttaquer/ContactTo/assets/145159480/2afe794d-3b47-4721-86b0-f6f2d92dfd5b)

- Setup connection to database


### Usage
The pgDbClient class provides methods to interact with the PostgreSQL database:

- IsConnection() - Check if connection to database is valid
- Count() - Get total number of contacts
- loadShortInfo() - Get list of contacts with ID, first name, last name and phone number
- loadAllInfo() - Get full details of a contact by ID
- Is() - Check if a contact exists
- Add() - Add a new contact
- Delete() - Delete a contact by ID
- Update() - Update details of an existing contact
- CountFavourite() - Get list of favourite contacts
- loadShortInfoFavourite() - Get list of favourite contacts
- IsFavourite() - Check if a contact is a favourite
- AddFavourite() - Mark a contact as favourite
- DeleteFavourite() - Remove a contact from favourites

The **FullContact** class represents a contact entity with all details.

The database connection settings like host, database name, user etc. can be configured in pgDbClient.

### Database Schema
The contacts are stored in a PostgreSQL database with the following schema:
- CONTACTS table contains the main contact details

``` sql
-- Table: public.CONTACTS

-- DROP TABLE IF EXISTS public."CONTACTS";

CREATE TABLE IF NOT EXISTS public."CONTACTS"
(
    "ID" integer NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 2147483647 CACHE 1 ),
    "IMIE" character varying(20) COLLATE pg_catalog."default" NOT NULL,
    "NAZWISKO" character varying(30) COLLATE pg_catalog."default",
    "TELEFON" character varying(15) COLLATE pg_catalog."default",
    "TEL_DOM" character varying(15) COLLATE pg_catalog."default",
    "FIRMA" character varying(30) COLLATE pg_catalog."default",
    "STANOWISKO" character varying(20) COLLATE pg_catalog."default",
    "EMAIL" character varying(30) COLLATE pg_catalog."default",
    "PSEUDONIM" character varying(20) COLLATE pg_catalog."default",
    CONSTRAINT "CONTACTS_pkey" PRIMARY KEY ("ID")
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."CONTACTS"
    OWNER to postgres;
```

-  CONTACTS_FAVOURITES table stores the favourite contacts  

``` sql
-- Table: public.ULUBIONE

-- DROP TABLE IF EXISTS public."ULUBIONE";

CREATE TABLE IF NOT EXISTS public."ULUBIONE"
(
    "ID" integer
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."ULUBIONE"
    OWNER to postgres;
```

### Dependencies
- libpqxx - C++ interface to PostgreSQL
- Qt - C++ framework to make GUI
