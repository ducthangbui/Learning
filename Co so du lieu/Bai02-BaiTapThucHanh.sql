--Câu 1: In ra tên các sinh viên đã học một môn học nào đó
--select SV.MaSV,TenSV,NamNhapHoc,SV.Khoa 
--from SV, Mon, KeHoach, KQ
--where SV.MaSV = KQ.MaSV
--		and KQ.MaKH = KeHoach.MaKH
--		and KeHoach.MaMH = Mon.MaMH


--Câu 2: Cho biết tên các môn học phải học ngay trước môn "C++"
--select Mon.MaMH, Mon.TenM, Mon.SoTinChi, Mon.Khoa
--from (select DieuKien.MaMHTruoc from Mon, DieuKien where Mon.TenM = 'C++' and DieuKien.MaMH = Mon.MaMH) AS X, 
--	Mon
--where X.MaMHTruoc = Mon.MaMH

--Câu 3: Cho biết tên tất cả các môn học phải học sau môn "Cơ sở dữ liệu"
--select * from Mon	
--select * from DieuKien

--select Mon.MaMH, Mon.TenM, Mon.SoTinChi, Mon.Khoa
--from (select * from Mon where Mon.TenM='CSDL') as X,
--	DieuKien, Mon
--where DieuKien.MaMHTruoc = X.MaMH and DieuKien.MaMH = Mon.MaMH

--Câu 4: Cho biết tên sinh viên và tên các môn học mà sinh viên đó tham gia với kết quả cuối khóa > 7đ
--select * from SV
--select * from KQ
--select * from KeHoach
--select * from Mon
--select SV.TenSV, Mon.TenM
--from SV, Mon, KQ, KeHoach
--where SV.MaSV = KQ.MaSV
--	and KQ.MaKH = KeHoach.MaKH
--	and Mon.MaMH = KeHoach.MaMH
--	and KQ.Diem > 7

--Câu 5: Cho bieest tên sinh viên và điểm trung bình của sinh viên đó trong từng học kỳ của từng năm học 
--select * from SV
--select * from KQ
--select * from KeHoach
--select distinct SV.TenSV, KQ.Diem
--from SV, KQ, KeHoach
--where SV.MaSV = KQ.MaSV

--Câu 6: Cho biết tên các sinh viên chỉ có nhiều nhất 2 môn học có điểm dưới trung bình
--select * from SV
--select * from KQ


--select *
--from SV, (select KQ.MaSV, count(KQ.MaSV) as c from KQ, SV where KQ.MaSV = SV.MaSV and KQ.Diem <= 5 group by KQ.MaSV) AS X
--where  X.c <= 2 and X.MaSV = SV.MaSV

--Câu 7: Cho biết sinh viên đạt điểm cao nhất(môn bất kỳ) trong số các sinh viên học năm thứ 4
--Chưa làm
--Câu 8: Cho biết tên sinh viên tham dự tất cả các môn học
--select * from SV
--select * from Mon
--select * from KeHoach

--select Sv.MaSV, SV.TenSV
--from (select count(MaMH)as SoLuongMon from Mon) as X,
--		(select SV.MaSV, count(KeHoach.MaMH) as c from KQ, SV, KeHoach, Mon where SV.MaSV = KQ.MaSV and KeHoach.MaKH = KQ.MaKH and Mon.MaMH = KeHoach.MaMH group by SV.MaSV) As Y,
--		SV
--where X.SoLuongMon = Y.c and SV.MaSV = Y.MaSV


--Câu 9: Hiện tên và mã của sinh viên có điểm cao nhất của những môn học
--trong năm học có nhiều khóa học nhất
select * from KeHoach

select max(X.m)
from
	(select count(KeHoach.Nam) as m, KeHoach.Nam
		from KeHoach
		group by KeHoach.Nam) as X

--Câu 10: Trong từng năm học, hiển thị học kỳ nào có số môn
--nhiều nhất. THông tin cần hiên: NAM,HocKy,SoMonNhieuNhat

