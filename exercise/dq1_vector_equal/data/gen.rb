def genOneFile(filename, n,m = n,equal = true)
  File.open(filename,"w") do |f|
    a =  n.times.map{ rand(100000) }
    if equal
      b = a
    else
      b = m.times.map{ rand(100000) }
    end
    f.puts "#{n} #{m}"
    f.puts a.join ' '
    f.puts b.join ' '
  end
end


genOneFile("1.in",10,10,false)
genOneFile("2.in",100,99)
genOneFile("3.in",10,500)
genOneFile("4.in",500)
genOneFile("5.in",500)
genOneFile("6.in",500)
genOneFile("7.in",1,10000)
genOneFile("8.in",20000,0)
genOneFile("9.in",50000,50000,false)
genOneFile("10.in",50000)

File.write("11.in",<<END
3 3
1 2 3
3 2 1
END
          )
File.write("12.in",<<END
3 2
1 2 3
1 2
END
          )
File.write("13.in",<<END
3 3
10 20 30
10 20 30
END
          )
File.write("14.in",<<END
3 2
9 9 9
9 9
END
          )
File.write("15.in",<<END
1 1
1
1
END
          )
File.write("16.in",<<END
2 2
5 5
5 5
END
          )
File.write("17.in",<<END
0 0
END
          )
File.write("18.in",<<END
0 1
10
END
          )
