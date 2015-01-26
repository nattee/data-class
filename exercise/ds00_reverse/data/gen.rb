def genOneFile(filename,n,a = rand(n), b = rand(n))
  a,b = b,a if a > b
  File.open(filename,'w') do |f|
    f.puts n
    f.puts n.times.to_a.shuffle.join ' '
    f.puts "#{a} #{b}"
  end
end

genOneFile('1.in',10)
genOneFile('2.in',100,10,10)
genOneFile('3.in',100,40,41)
genOneFile('4.in',100,50,52)
genOneFile('5.in',100)
genOneFile('6.in',100)
genOneFile('7.in',100)
genOneFile('8.in',100)
genOneFile('9.in',100)
genOneFile('10.in',100)
