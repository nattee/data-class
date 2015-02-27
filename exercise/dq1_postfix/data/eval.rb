
def eval_post(filename)
  s = []
  File.open(filename,"r") do |f|
    n = f.gets.chomp.to_i
    n.times do
      a,b = f.gets.split.map{|x| x.to_i}
      if a == 0
        r = 0
        case b
        when 0
          r = s[-2] + s[-1]
        when 1
          r = s[-2] - s[-1]
        when 2
          r = s[-2] * s[-1]
        when 3
          r = (s[-2] / s[-1]).to_i
        end
        puts "#{s[-2]} #{b} #{s[-1]} result = #{r}"
        s.pop
        s.pop
        s << r
      else
        s << b
      end
    end
    puts "result = #{s[0]}"


  end
end


eval_post('3.in')
