CREATE TABLE Jernbanestasjon(
    Navn VARCHAR(40) NOT NULL,
    Høydemeter INTEGER NOT NULL,
    CONSTRAINT Stasjon_PK PRIMARY KEY (Navn)
);

CREATE TABLE Banestrekning(
    ID INTEGER NOT NULL,
    Navn VARCHAR(40) NOT NULL,
    Fremdriftsenergi VARCHAR(40) NOT NULL,
    Startstasjon VARCHAR(40) NOT NULL,
    Endestasjon VARCHAR(40) NOT NULL,
    CONSTRAINT Strekning_PK PRIMARY KEY (ID),
    CONSTRAINT StrekningStart_FK FOREIGN KEY (Startstasjon) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE,
    CONSTRAINT StrekningSlutt_FK FOREIGN KEY (Endestasjon) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE
);

CREATE TABLE DelstrekningIBane(
    BanestrekningID INTEGER NOT NULL,
    DelstrekningID INTEGER NOT NULL,
    CONSTRAINT Strekning_PK PRIMARY KEY (BanestrekningID, DelstrekningID),
    CONSTRAINT DelstrekningIBane_FK1 FOREIGN KEY (BanestrekningID) REFERENCES Banestrekning(ID)
        ON UPDATE CASCADE,
    CONSTRAINT DelstrekningIBane_FK2 FOREIGN KEY (DelstrekningID) REFERENCES Delstrekning(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Delstrekning(
    ID INTEGER NOT NULL,
    Lengde VARCHAR(40) NOT NULL,
    Sportype VARCHAR(40) NOT NULL,
    Stasjon1 VARCHAR(40) NOT NULL,
    Stasjon2 VARCHAR(40) NOT NULL,
    CONSTRAINT Strekning_PK PRIMARY KEY (ID),
    CONSTRAINT Stasjon1_FK FOREIGN KEY (Stasjon1) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE,
    CONSTRAINT Stasjon2_FK FOREIGN KEY (Stasjon2) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE
);

CREATE TABLE StrekningPåRute(
    TogruteID INTEGER NOT NULL,
    DelstrekningID INTEGER NOT NULL,
    Ankomsttid TIME,
    Avgangstid TIME,
    CONSTRAINT Rute_PK PRIMARY KEY (TogruteID, DelstrekningID),
    CONSTRAINT TogruteID_FK FOREIGN KEY (TogruteID) REFERENCES Togrute(ID)
        ON UPDATE CASCADE,
    CONSTRAINT DelstrekningID_FK FOREIGN KEY (DelstrekningID) REFERENCES Delstrekning(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Togrute(
    ID INTEGER NOT NULL,
    Banestrekning VARCHAR(40) NOT NULL,
    Startstasjon VARCHAR(40) NOT NULL,
    Endestasjon VARCHAR(40) NOT NULL,
    Togrutetabell INTEGER NOT NULL,
    Vognoppsett INTEGER NOT NULL,
    Avgangstid TIME NOT NULL,
    Ankomsttid TIME NOT NULL,
    CONSTRAINT Rute_PK PRIMARY KEY (ID),
    CONSTRAINT Banestrekning_FK FOREIGN KEY (Banestrekning) REFERENCES Banestrekning(ID)
        ON UPDATE CASCADE,
    CONSTRAINT Startstasjon_FK FOREIGN KEY (Startstasjon) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE,
    CONSTRAINT Endestasjon_FK FOREIGN KEY (Endestasjon) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE,
    CONSTRAINT Togrutetabell_FK FOREIGN KEY (Togrutetabell) REFERENCES Togrutetabell(ID)
        ON UPDATE CASCADE,
    CONSTRAINT Vognoppsett_FK FOREIGN KEY (Vognoppsett) REFERENCES Vognoppsett(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Togrutetabell(
    ID INTEGER NOT NULL,
    CONSTRAINT Tabell_PK PRIMARY KEY (ID)
);

CREATE TABLE StasjonerITabell(
    TogrutetabellID INTEGER NOT NULL,
    Jernbanestasjon VARCHAR(40) NOT NULL,
    Avgangstid TIME,
    Ankomsstid TIME,
    CONSTRAINT StasjonerITabell_PK PRIMARY KEY (TogrutetabellID, Jernbanestasjon),
    CONSTRAINT StasjonerITabell_FK1 FOREIGN KEY (TogrutetabellID) REFERENCES Togrutetabell(ID)
        ON UPDATE CASCADE,
    CONSTRAINT StasjonerITabell_FK2 FOREIGN KEY (Jernbanestasjon) REFERENCES Jernbanestasjon(Navn)
        ON UPDATE CASCADE
);

CREATE TABLE Togruteforekomst(
    ID INTEGER NOT NULL,
    Dato DATE NOT NULL,
    Togrute INTEGER NOT NULL,
    CONSTRAINT togruteforekomst_PK PRIMARY KEY (ID)
    CONSTRAINT togruteforekomst_FK FOREIGN KEY (Togrute) REFERENCES Togrute(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Billett(
    ID INTEGER NOT NULL,
    Togruteforekomst INTEGER NOT NULL,
    SengNummer INTEGER NOT NULL,
    SengVogn INTEGER NOT NULL,
    SeteNummer INTEGER NOT NULL,
    SeteVogn INTEGER NOT NULL,
    Kundeordrenummer INTEGER NOT NULL,
    CONSTRAINT Billett_PK PRIMARY KEY (ID),
    CONSTRAINT Billett_FK1 FOREIGN KEY (SengNummer, SengVogn) REFERENCES Seng (VognID, Nummer)
        ON UPDATE CASCADE,
    CONSTRAINT Billett_FK2 FOREIGN KEY (SeteNummer, SeteVogn) REFERENCES Sete (VognID, Nummer)
        ON UPDATE CASCADE,
    CONSTRAINT Billett_FK3 FOREIGN KEY (Kundeordrenummer) REFERENCES Kundeordre (Ordrenummer)
        ON UPDATE CASCADE
);

CREATE TABLE BillettTilStrekning(
    BillettID INTEGER NOT NULL,
    DelstrekningID INTEGER NOT NULL,
    CONSTRAINT BillettTilStrekning_PK PRIMARY KEY (BillettID, DelstrekningID),
    CONSTRAINT BillettTilStrekning_FK1 FOREIGN KEY (BillettID) REFERENCES Billett (ID)
        ON UPDATE CASCADE,
    CONSTRAINT BillettTilStrekning_FK2 FOREIGN KEY (DelstrekningID) REFERENCES Delstrekning (ID)
        ON UPDATE CASCADE
);

CREATE TABLE Kundeordre(
    Ordrenummer INTEGER NOT NULL,
    Kunde INTEGER NOT NULL,
    Tidspunkt TIMESTAMP NOT NULL,
    CONSTRAINT Kundeordre_PK PRIMARY KEY (Ordrenummer),
    CONSTRAINT Kundeordre_FK FOREIGN KEY (Kunde) REFERENCES Kunde (Kundenummer)
        ON UPDATE CASCADE
);

CREATE TABLE Kunde(
    Kundenummer INTEGER NOT NULL,
    Navn VARCHAR(40) NOT NULL,
    Epostadresse VARCHAR(40) NOT NULL,
    Mobilnummer INTEGER NOT NULL,
    KunderegisterID INTEGER NOT NULL,
    CONSTRAINT Kunde_PK PRIMARY KEY (Kundenummer),
    CONSTRAINT Kunderegister_FK FOREIGN KEY (KunderegisterID) REFERENCES Kunderegister(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Kunderegister(
    ID INTEGER NOT NUll,
    CONSTRAINT Kunderegister_PK PRIMARY KEY (ID)
);

CREATE TABLE Operatør(
    Operatørnavn VARCHAR(40) NOT NUll,
    KunderegisterID INTEGER NOT NULL,
    CONSTRAINT Operatør_PK PRIMARY KEY (Operatørnavn),
    CONSTRAINT Kunderegister_FK FOREIGN KEY (KunderegisterID) REFERENCES Kunderegister(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Vogn(
    ID INTEGER NOT NUll,
    Navn VARCHAR(40),
    Operatørnavn VARCHAR(40),
    Vogntype VARCHAR(40) NOT NULL, -- Sittevogn || Sovevogn
    CONSTRAINT Vogn_PK PRIMARY KEY (ID),
    CONSTRAINT Operatør_FK FOREIGN KEY (Operatørnavn) REFERENCES Operatør(Operatørnavn)
        ON UPDATE CASCADE
);

CREATE TABLE Vognoppsett(
    ID INTEGER NOT NULL,
    CONSTRAINT Vognoppsett_PK PRIMARY KEY (ID)
);

CREATE TABLE VognIOppsett(
    VognID INTEGER NOT NUll,
    VognoppsettID INTEGER NOT NULL,
    Nummer INTEGER NOT NULL,
    CONSTRAINT VognIOppsett_PK PRIMARY KEY (VognID, VognoppsettID),
    CONSTRAINT Vogn_FK FOREIGN KEY (VognID) REFERENCES Vogn(ID)
        ON UPDATE CASCADE,
    CONSTRAINT Vognoppsett_FK FOREIGN KEY (VognoppsettID) REFERENCES Vognoppsett(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Rad(
    VognID INTEGER NOT NULL,
    Nummer INTEGER NOT NULL,
    CONSTRAINT Rad_PK PRIMARY KEY (VognID, Nummer),
    CONSTRAINT Vogn_FK FOREIGN KEY (VognID) REFERENCES Vogn(ID)
        ON UPDATE CASCADE
);

CREATE TABLE Sete(
    VognID INTEGER NOT NULL,
    Nummer INTEGER NOT NUll,
    Radnummer INTEGER,
    CONSTRAINT Sete_PK PRIMARY KEY (VognID, Nummer),
    CONSTRAINT Vogn_FK FOREIGN KEY (VognID) REFERENCES Vogn(ID)
        ON UPDATE CASCADE,
    CONSTRAINT Rad_FK FOREIGN KEY (Radnummer, VognID) REFERENCES Rad(VognID, Nummer)
        ON UPDATE CASCADE
);

CREATE TABLE Kupe(
  VognID INTEGER NOT NULL,
  Nummer INTEGER NOT NULL,
  CONSTRAINT Kupe_PK PRIMARY KEY (VognID, Nummer),
  CONSTRAINT Vogn_FK FOREIGN KEY (VognID) REFERENCES Vogn(ID)
        ON UPDATE CASCADE 
);

CREATE TABLE Seng(
    VognID INTEGER NOT NULL,
    Nummer INTEGER NOT NULL,
    Kupenummer INTEGER,
    CONSTRAINT Seng_PK PRIMARY KEY (VognID, Nummer),
    CONSTRAINT Vogn_FK FOREIGN KEY (VognID) REFERENCES Vogn(ID)
        ON UPDATE CASCADE,
    CONSTRAINT Kupe_FK FOREIGN KEY (Kupenummer) REFERENCES Kupe(VognID)
        ON UPDATE CASCADE
);
