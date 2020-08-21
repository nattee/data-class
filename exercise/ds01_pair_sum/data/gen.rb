def genOneFile(filename,n,m,range_a: 0..999999, range_x: 0..2000000)
  File.open(filename,'w') do |f|
    f.puts [n,m].join ' '
    a = n.times.map{ rand(range_a) }
    f.puts a.join ' '
    a = m.times.map{ rand(range_x) }
    f.puts a.join ' '
  end
end

genOneFile('1.in',3,5,range_a: 1..10, range_x: 1..10)
genOneFile('2.in',10,10,range_a: 1..10, range_x: 1..20)

genOneFile '3.in',100,1000
genOneFile '4.in',300,1000
genOneFile '5.in',500,1000

#we got lucky, random for the first time and it generate the case when a[i] + a[i] = x
genOneFile '6.in', 1_000,1_000
genOneFile '7.in', 4_000,5_000
genOneFile '8.in', 6_000,6_000
genOneFile '9.in', 8_000,8_000
genOneFile '10.in', 10_000,10_000
