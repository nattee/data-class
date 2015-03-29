@name = []
File.open('name.txt','r').read.each_line do |line|
  @name << line.split[0].capitalize
end
@name.shuffle!

def genOneFile(filename,n,k)
  File.open(filename,'w') do |f|
    f.puts [n,k].join ' '
    n.times do |i|
      f.puts [@name[i],rand(100)].join ' '
    end
  end
end


genOneFile('1.in',10,5)
genOneFile('2.in',50,5)
genOneFile('3.in',100,20)
genOneFile('4.in',1000,500)
genOneFile('5.in',3000,1000)
genOneFile('6.in',5000,5)
genOneFile('7.in',5000,1000)
genOneFile('8.in',5000,2000)
genOneFile('9.in',5000,3000)
genOneFile('10.in',5000,5000)
