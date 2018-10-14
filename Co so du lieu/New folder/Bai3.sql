use demo3
GO

--insert into Student(Name,Age)
--values('Nguyen Hong Ha',20)
--insert into Student(Name,Age)
--values('Truong Ngoc Anh',30)
--insert into Student(Name,Age)
--values('Tuan Minh',25)
--insert into Student(Name,Age)
--values('Dan Truong',22)

--select * from Student

--insert into Test(Name)
--values('EPC')
--insert into Test(Name)
--values('DWMX')
--insert into Test(Name)
--values('SQL1')
--insert into Test(Name)
--values('SQL2')

--select * from Test

--insert into StudentTest(RN,TestID,Date,Mark)
--values('1',1,'7/17/2006',8)
--insert into StudentTest(RN,TestID,Date,Mark)
--values('1',2,'7/18/2006',5)
--insert into StudentTest(RN,TestID,Date,Mark)
--values('1',3,'7/19/2006',7)
--insert into StudentTest(RN,TestID,Date,Mark)
--values(2,1,'7/17/2006',7)
--insert into StudentTest(RN,TestID,Date,Mark)
--values(2,2,'7/18/2006',4)
--insert into StudentTest(RN,TestID,Date,Mark)
--values(2,3,'7/19/2006',2)
--insert into StudentTest(RN,TestID,Date,Mark)
--values(3,1,'7/17/2006',10)
--insert into StudentTest(RN,TestID,Date,Mark)
--values(3,3,'7/18/2016',1)
--select * from StudentTest

--B�i 1: ??a ra tu?i trung b�nh c?a c�c h?c vi�n
--select AVG(Age) as 'Tu?i TB' from Student

--B�i 2: T�m h?c vi�n c� tu?i cao nh?t
--select Name as 'H?c sinh c� tu?i cao nh?t'
--from Student
--where Age = (select MAX(Age) from Student)

--B�i 3: T�nh t?ng tu?i c?a h?c vi�n
--select SUM(Age) as 'T?ng tu?i' from Student

--B�i 4: T�nh xem m?i h?c sinh ?� thi ???c bao nhi�u l?n
--select Name as 'T�n',
--		(select COUNT(RN) from StudentTest where StudentTest.RN = st.RN) as 'S? l?n thi'
--from Student st

--B�i 5: T�m nh?ng h?c vi�n ??t ?i?m cao nh?t
--select * 
--from StudentTest
--where Mark = (select MAX(Mark) from StudentTest)

--B�i 6: ??a ra ?i?m c?a h?c vi�n d??i d?ng 4 ch? s?, 2 ch? s? sau d?u ph?y
--select Student.RN, Name, CONVERT(decimal(4,2),Mark) as Mark
--from StudentTest, Student
--where StudentTest.RN = Student.RN

--B�i 7: Hi?n th? danh s�ch c�c h?c vi�n ?� tham gia thi , c�c m�n thi ???c thi b?i c�c h?c vi�n
--?i?m thi v� ng�y thi

--select Student.Name as 'Student Name', Test.Name as 'Test Name', Convert(decimal(4,2),Mark) as Mark, Date as Date
--from Student, StudentTest, Test
--where Student.RN = StudentTest.RN
--	and StudentTest.TestID = Test.TestID

--B�i 8: Hi?n th? danh s�ch c�c h?c vi�n ch?a thi m�n n�o
--select Student.RN, Student.Name, Age
--from Student
--where Student.RN not in (select RN from StudentTest)

--B�i 9: Hi?n th? danh s�ch h?c vi�n ph?i thi l?i v� ?i?m thi (?i?m thi ph?i thi l?i l� ?i?m < 5)
--select Student.Name as 'Student Name', 
--	Test.Name as 'Test name',
--	StudentTest.Mark, StudentTest.Date
--into #tmp
--from Student, StudentTest, Test
--where Student.RN = StudentTest.RN 
--	and StudentTest.TestID = Test.TestID
----	and Mark = (select Mark from StudentTest where StudentTest.Mark < 5)

--select * 
--from #tmp
--where #tmp.Mark < 5

--drop table #tmp

--B�i 10: Hi?n th? danh s�ch sinh vi�n v� ?i?m trung b�nh c?a c�c m�n ?� thi
--Danh s�ch ph?i s?p x?p theo th? t? ?i?m trung b�nh gi?m d?n
select st.Name as 'Student Name',
		AVG(StudentTest.Mark) as Average
from Student st, StudentTest
where st.RN = StudentTest.RN
group by st.Name
order by  Average DESC

--select * from StudentTest