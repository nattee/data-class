def genOneFile(filename, n)
  n -= 1 if n.even?
  d = []
  s = []
  while (n > 0) do
    if (s.length >= 2 and rand(2) == 0) or (n < s.length)
      op,r = 0,0
      loop do
        op = rand(4)
        case op
        when 0
          r = s[-2] + s[-1]
        when 1
          r = s[-2] - s[-1]
        when 2
          r = s[-2] * s[-1]
        when 3
          next if s[-1] <= 0
          next if s[-2] < 0
          r = (s[-2] / s[-1]).to_i
        end
        break if r.abs < 1000000
      end
      #puts "#{s[-2]} #{op} #{s[-1]}"
      s.pop
      s[-1] = r
      d << [0,op]
    else
      d << [1,rand(1000)]
      s << d[-1][1]
    end
    n -= 1
  end
  puts "result = #{s[0]}"
  File.open(filename,"w") do |f|
    f.puts d.length
    d.each do |i|
      f.puts i.join ' '
    end
  end
end

genOneFile('1.in',5)
genOneFile('2.in',10)
genOneFile('3.in',20)
genOneFile('4.in',500)
genOneFile('5.in',500)
genOneFile('6.in',1000)
genOneFile('7.in',5000)
genOneFile('8.in',5000)
genOneFile('9.in',5000)
genOneFile('10.in',5000)
