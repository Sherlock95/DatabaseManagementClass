drop table if exists Student;
drop table if exists Faculty;
drop table if exists Class;
drop table if exists Enroll;
CREATE TABLE Student(stuId VARCHAR(6), lastName VARCHAR(20) NOT NULL, firstName VARCHAR(20) NOT NULL, major VARCHAR(10), credits int(3) DEFAULT 0, CONSTRAINT Student_stuId_pk PRIMARY KEY (stuId), CONSTRAINT Student_credits_cc CHECK ((credits>=0) AND (credits < 150)));
CREATE TABLE Faculty(facId VARCHAR(6), name VARCHAR(20) NOT NULL, department VARCHAR(20), rank VARCHAR(10), CONSTRAINT Faculty_facId_pk PRIMARY KEY (facId));
CREATE TABLE Class(classNumber VARCHAR(8), facId VARCHAR(6), schedule VARCHAR(8), room VARCHAR(6), CONSTRAINT Class_classNumber_pk PRIMARY KEY (classNumber), CONSTRAINT Class_facId_fk FOREIGN KEY (facId) REFERENCES Faculty (facId)  ON DELETE SET NULL, CONSTRAINT Class_schedule_room_uk UNIQUE (schedule, room));
CREATE TABLE Enroll(stuId VARCHAR(6), classNumber VARCHAR(8), grade VARCHAR(2), CONSTRAINT Enroll_classNumber_stuId_pk PRIMARY KEY (classNumber, stuId), CONSTRAINT Enroll_classNumber_fk FOREIGN KEY (classNumber) REFERENCES Class (classNumber) ON DELETE CASCADE, CONSTRAINT Enroll_stuId_fk FOREIGN KEY (stuId) REFERENCES Student (stuId) ON DELETE CASCADE);
insert into Student values (S0001, alThor, Rand, Taveren, 103);
insert into Student values (S0002, Cauthon, Matrim, Taveren, 87);
insert into Student values (S0003, Aybara, Perrin, Taveren, 43);
insert into Student values (S1003, Benthusen, Trevor, Math, 133);
insert into Student values (S1009, Summers, Brittney, Art, 24);
insert into Student values (S1017, Ramirez, Alejandro, CSC, 129);
insert into Student values (S1234, Polk, DeWae, CSC, 12);
insert into Student values (S2001, Dowl, Bob, History, 95);
insert into Student values (S2002, Wallis, Arthur, Math, 36);
insert into Student values (S2005, Dunnum, Olivea, History, 32);
insert into Student values (S2035, Charney, Bob, CSC, 120);
insert into Student values (S2036, Shennum, Micah, CSC, 120);
insert into Student values (S2037, Lynch, Dave, DSTC, 90);
insert into Student values (S3002, Jones, John, Business, 59);
insert into Student values (S3003, Smith, Sean, CSC, 85);
insert into Student values (S3005, Evans, Ellen, Math, 27);
insert into Student values (S5678, Sulek, Kyle, Art, 0);
insert into Student values (S9101, Day, Christy, Math, 135);
insert into Faculty values (F100, Thomdril, Gleeman, Master);
insert into Faculty values (F134, Teevis, History, Professor);
insert into Faculty values (F201, Rouse, CSC, Professor);
insert into Faculty values (F501, Strouse, ME, Professor);
insert into Faculty values (F701, Knouse, Math, Professor);
insert into Class values (ART106B, F134, TuThF3, H221);
insert into Class values (BUS111, F108, TuTh8, B101);
insert into Class values (CSC222, F107, MWF12, C202);
insert into Class values (GRE101A, F202, TuTh12, L140);
insert into Class values (HST303B, F134, MWF3, H225);
insert into Class values (JUG203B, F100, TuTh4, O107);
insert into Class values (KNV101A, F100, MWF9, O201);
insert into Class values (ME203A, F501, MWF8, H221);
insert into Class values (ME401A, F501, TuTh11, M110);
insert into Class values (MTH104A, F107, TuTh3, H223);
insert into Class values (MTH105C, F107, MWF3, M110);
insert into Class values (MTH301A, F201, MWF9, H103);
insert into Enroll values (S1009, ART103A, A);
insert into Enroll values (S2037, ART103A, A);
insert into Enroll values (S9101, ART106B, B);
insert into Enroll values (S0003, AXE302A, A);
insert into Enroll values (S3002, BUS111, B);
insert into Enroll values (S1017, CSC201A, A);
insert into Enroll values (S2035, CSC201A, B);
insert into Enroll values (S2036, CSC201A, A);
insert into Enroll values (S2037, CSC201A, B);
insert into Enroll values (S2036, CSC203A, A);
insert into Enroll values (S3003, CSC222, A);
insert into Enroll values (S3005, CSC222, D);
insert into Enroll values (S2035, GRE101A, A);
insert into Enroll values (S1234, HST303B, A);
insert into Enroll values (S5678, HST303B, A);
insert into Enroll values (S0001, JUG203B, B);
insert into Enroll values (S0002, JUG203B, A);
insert into Enroll values (S0003, JUG203B, C);
insert into Enroll values (S0001, KNV101A, D);
insert into Enroll values (S0002, KNV101A, A);
insert into Enroll values (S2001, ME203A, A);
insert into Enroll values (S2005, ME203A, B);
insert into Enroll values (S2002, ME401A, C);
insert into Enroll values (S2037, MTH103C, C);
insert into Enroll values (S1017, MTH104A, B);
insert into Enroll values (S2035, MTH301A, B);
insert into Enroll values (S2036, MTH301A, A);
insert into Enroll values (S0002, SRT101C, A);
insert into Enroll values (S0003, SRT101C, B);
insert into Enroll values (S0001, SWD101A, A);