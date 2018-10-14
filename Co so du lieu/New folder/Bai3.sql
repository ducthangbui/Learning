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

--Bài 1: ??a ra tu?i trung bình c?a các h?c viên
--select AVG(Age) as 'Tu?i TB' from Student

--Bài 2: Tìm h?c viên có tu?i cao nh?t
--select Name as 'H?c sinh có tu?i cao nh?t'
--from Student
--where Age = (select MAX(Age) from Student)

--Bài 3: Tính t?ng tu?i c?a h?c viên
--select SUM(Age) as 'T?ng tu?i' from Student

--Bài 4: Tính xem m?i h?c sinh ?ã thi ???c bao nhiêu l?n
--select Name as 'Tên',
--		(select COUNT(RN) from StudentTest where StudentTest.RN = st.RN) as 'S? l?n thi'
--from Student st

--Bài 5: Tìm nh?ng h?c viên ??t ?i?m cao nh?t
--select * 
--from StudentTest
--where Mark = (select MAX(Mark) from StudentTest)

--Bài 6: ??a ra ?i?m c?a h?c viên d??i d?ng 4 ch? s?, 2 ch? s? sau d?u ph?y
--select Student.RN, Name, CONVERT(decimal(4,2),Mark) as Mark
--from StudentTest, Student
--where StudentTest.RN = Student.RN

--Bài 7: Hi?n th? danh sách các h?c viên ?ã tham gia thi , các môn thi ???c thi b?i các h?c viên
--?i?m thi và ngày thi

--select Student.Name as 'Student Name', Test.Name as 'Test Name', Convert(decimal(4,2),Mark) as Mark, Date as Date
--from Student, StudentTest, Test
--where Student.RN = StudentTest.RN
--	and StudentTest.TestID = Test.TestID

--Bài 8: Hi?n th? danh sách các h?c viên ch?a thi môn nào
--select Student.RN, Student.Name, Age
--from Student
--where Student.RN not in (select RN from StudentTest)

--Bài 9: Hi?n th? danh sách h?c viên ph?i thi l?i và ?i?m thi (?i?m thi ph?i thi l?i là ?i?m < 5)
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

--Bài 10: Hi?n th? danh sách sinh viên và ?i?m trung bình c?a các môn ?ã thi
--Danh sách ph?i s?p x?p theo th? t? ?i?m trung bình gi?m d?n
select st.Name as 'Student Name',
		AVG(StudentTest.Mark) as Average
from Student st, StudentTest
where st.RN = StudentTest.RN
group by st.Name
order by  Average DESC

--select * from StudentTest