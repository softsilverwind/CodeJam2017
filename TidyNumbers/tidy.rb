class Array
	def sorted?
		self.each_cons(2).all? { |x, y| x <= y }
	end
end

def tidy arr
	n = arr.length

	return arr if arr.sorted?

	(n-2).downto 0 do |i|
		arr[i+1] = 9

		i.downto 0 do |j|
			if arr[j] > 0
				arr[j] -= 1
				break
			else
				arr[j] = 9
			end
		end

		return arr if arr.sorted?
	end
end

n = gets.to_i

n.times do |i|
	inp = gets.strip.split('').map(&:to_i)
	puts "Case ##{i + 1}: #{tidy(inp).join('').to_i}"
end
