--- Die ersten 5 Tabellen bilden Enumerationen ab.
--- Benutzung in der letzten Tabelle (statistikeintrag)

create table Geschlecht (
  Id text primary key not null, 
  wert integer
);
insert into Geschlecht(Id, wert) values('weibl', 1);
insert into Geschlecht(Id, wert) values('maennl', 2);

create table dasAlter (   -- Alter ist sqlite-keyword, deswegen dasAlter
  Id text primary key not null, 
  wert integer
);
insert into dasAlter(Id, wert) values('lt20', 1);
insert into dasAlter(Id, wert) values('20_22', 2);
insert into dasAlter(Id, wert) values('23_25', 3);
insert into dasAlter(Id, wert) values('gt25', 4);

create table Herkunft (
  Id text primary key not null, 
  wert integer
);
insert into Herkunft(Id, wert) values('D', 1);
insert into Herkunft(Id, wert) values('EU', 2);
insert into Herkunft(Id, wert) values('RestDerWelt', 3);

create table Dauer (
  Id text primary key not null, 
  wert integer
);
insert into Dauer(Id, wert) values('Regel', 1);
insert into Dauer(Id, wert) values('RegelPlus1', 2);
insert into Dauer(Id, wert) values('laenger', 3);

create table Fach (
  Id text primary key not null, 
  wert integer
);
insert into Fach(Id, wert) values('Technik', 1);
insert into Fach(Id, wert) values('Geisteswiss', 2);
insert into Fach(Id, wert) values('Sonst', 3);

create table statistikeintrag (
 Id integer primary key not null,
 GeschlechtId text not null,
 AlterId text not null,
 HerkunftId text not null,
 DauerId text not null,
 FachId text not null,
 foreign key (GeschlechtId) references Geschlecht (Id),
 foreign key (AlterId) references dasAlter (Id)
 foreign key (HerkunftId) references Herkunft (Id)
 foreign key (DauerId) references Dauer (Id)
 foreign key (FachId) references Fach (Id)
);
