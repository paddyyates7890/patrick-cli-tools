CREATE TABLE DB_VERSION(
    ID INTEGER PRIMARY KEY,
    VERSION INTEGER,
    VDATE DATE
);

INSERT INTO DB_VERSION(VERSION, VDATE) VALUES(4, '2024-03-16');