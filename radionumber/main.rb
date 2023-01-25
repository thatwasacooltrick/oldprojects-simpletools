#Calvin Smith
#programatically generate HTML for a meme
fileout = "<b>What is your phone number?</b><br><form>"
number = 7140300000
while number < 7140301000 do
    number = number + 1
    fileout += "<input type=\"radio\" id=\"#{number}\" name=\"fav_language\" value=\"#{number}\">   <label for=\"#{number}\">#{number}</label>"
   if number % 7 == 0 then
    fileout += "<br>"
   end
end
fileout += "</form>"

File.write("index.html", fileout)
