use demo

--Hiển thị danh sách học sinh
--SELECT studentid as 'Mã Sinh Viên',
--		studentname as 'Tên sinh viên',
--		age as 'Tuổi',
--		email as 'Email'
--	from student

--Hiển thị danh sách tất cả các lớp học
--select classid as 'Mã lớp',
--		classname as 'Tên lớp'
--from classes

--Tính điểm trung bình các môn học có sắp xếp theo thứ tự điểm từ cao xuống thấp
--select subjectname as 'Tên môn học'
--		,AVG(mark) as 'Điểm trung bình'
--from marks 
--inner join subjects on subjects.subjectid = marks.subjectid
--group by (subjectname)
--order by AVG(mark) desc

--Hiển thị môn học có học sinh thi được điểm cao nhất

--Cách 1
--select Top 1 [subjectname] as 'Môn học có điểm cao nhất'
--	,MAX(mark) as kq
--into #b
--from subjects, marks

--where subjects.subjectid = marks.subjectid 
--group by subjectname
--order by kq desc

--select top 1 subjects.subjectname as 'Môn học có điểm cao nhất'
--from #b, subjects
--drop table #b

--Cách 2:
--select top 1 subjects.subjectname as 'Môn học có điểm cao nhất'
--from subjects, marks
--where mark = (select MAX(mark) from marks) 

--Sắp xếp điểm theo thứ bậc từ cao xuống thấp của từng môn
--select subjects.subjectid as 'Mã môn học'
--	, subjectname as 'Tên môn học'
--	, student.studentid as 'Mã sinh viên'
--	, studentname as 'Tên sinh viên'
--	, mark as 'Điểm'
--		,rank() over (partition by subjects.subjectid order by mark desc) as 'Thứ bậc'
--from subjects, student, marks
--where subjects.subjectid = marks.subjectid

--Hiển thị top 3 bản ghi có số điểm cao nhất sử dụng hàm top với with ties()
--select top (3) with TIES mark, subjects.subjectname, student.studentname
--from marks, subjects, student
--order by mark desc; 

--Hiển thị thông tin điểm được nhóm theo các môn học
--select 
--	subjectname as 'Tên môn học'
--	--, student.studentid as 'Mã sinh viên'
--	, studentname as 'Tên sinh viên'
--	, mark as 'Điểm'
--		,rank() over (order by mark desc) as 'Thứ bậc'
--from subjects, student, marks
--where subjects.subjectid = marks.subjectid

--Hiển thị danh sách sinh viên với Status = 0(Đang theo học) và Status = 1(Nghỉ học)

--create table #tmp
--(
--	Status bit,
--	NameStatus nvarchar(50)
--)

--declare @nameStatus nvarchar(50)
--set @nameStatus = N'Nghỉ học';
--insert into #tmp (Status,NameStatus)
--values (1,@nameStatus)

--select * from #tmp

--select studentid as 'Mã SV',
--		studentname as 'Tên SV',
--		email as 'Email',
--		NameStatus as 'Trạng thái'
--from student, #tmp
--where student.Status = #tmp.Status

--drop table #tmp

--Thêm mới 1 học viên
--insert into student
--values (N'Nguyễn Hồng Sơn','26','son@sport.vn','0')

--Cập nhật tuổi = 30 cho sinh viên với mã sinh viên = 6 và status = 1
--update student
--set age = 30, Status = 1
--where studentid = 6

select studentid as 'Mã SV',
		studentname as 'Tên SV',
		age as 'Tuổi',
		email as 'Email',
		Status as 'Trạng thái'
from student
where studentname like 'n%'
