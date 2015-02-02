$a=File.read("mobydick.txt").split(/[ \n\t'",.?!:;\[\]\(\)]/).uniq


def genOneFile(filename, n)
  File.open(filename,"w") do |f|
    f.puts n
    n.times do
      loop do
        st = $a[rand($a.size())]
        unless st == ''
          f.puts st
          break
        end
      end
    end
  end
end


genOneFile("1.in",10)
genOneFile("2.in",100)
genOneFile("3.in",500)
genOneFile("4.in",1000)
genOneFile("5.in",3000)
genOneFile("6.in",5000)
genOneFile("7.in",10000)
genOneFile("8.in",20000)
genOneFile("9.in",30000)
genOneFile("10.in",50000)
