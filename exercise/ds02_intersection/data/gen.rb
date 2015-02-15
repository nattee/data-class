def genOneFile(filename, n,m = n)
  File.open(filename,"w") do |f|
    a =  n.times.map{ rand([n,m].max / 2  ) }
    b =  m.times.map{ rand([n,m].max / 2  ) }
    f.puts "#{n} #{m}"
    f.puts a.join ' '
    f.puts b.join ' '
  end
end


genOneFile("1.in",10,10)
genOneFile("2.in",100,99)
genOneFile("3.in",10,500)
genOneFile("4.in",500)
genOneFile("5.in",500)
genOneFile("6.in",500)
genOneFile("7.in",1000)
genOneFile("8.in",5000)
genOneFile("9.in",5000,10)
genOneFile("10.in",10,5000)

File.write("11.in",<<END
4 4
4 1 3 2
5 4 2 9
END
          )
File.write("12.in",<<END
4 2
1 2 3 4
1 1
END
          )
File.write("13.in",<<END
4 2
1 1 3 4
1 1
END
          )
File.write("14.in",<<END
3 5
1 2 3
20 30 50 6 7
END
          )
File.write("15.in",<<END
4 4
2 2 3 3
3 2 2 3
END
          )
File.write("16.in",<<END
2 2
100 50
50 100
END
          )
