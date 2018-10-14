use demo2

--insert into Customer(Name)
--values('John Nguyen')
--insert into Customer(Name)
--values('Bin Laden')
--insert into Customer(Name)
--values('Bill CLinton')
--insert into Customer(Name)
--values('Thomas Hardy')
--insert into Customer(Name)
--values('Anna Tran')
--insert into Customer(Name)
--values('Bob Carr')

--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('2','Nuclear Bomb','01/12/2002')
--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('3','Missile','02/03/2000')
--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('2','Jet-1080','03/08/2004')
--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('1','Beers','12/05/2001')
--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('4','Asian Food','04/10/2002')
--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('6','Wine','08/03/2002')
--insert into Orders(CustomerID,ProductName,DateProcessed)
--values('5','Milk','02/05/2002')

--select * from Orders

select * from Orders where DateProcessed between '01-01-2001' and '01-01-2004' 