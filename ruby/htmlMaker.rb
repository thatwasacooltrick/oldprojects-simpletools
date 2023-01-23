#Calvin Smith
#1/31/19,
#Quick ruby program to make it super easy to do the HTML exercises. 
puts " Website Creator 2019!"
puts "gimme a title please:"
pageHeader = gets.to_s
puts "gimme some body"
pageBody = gets.to_s 
puts "gimme an image name (BE EXACT!!)"
imagesrc = gets.to_s #include the file extension

#I'll add in the list manually for the Saving Money site cause I'm bored, but later I'll put in a method to allow you to make a <ul> via CMD






result = "<!DOCTYPE html>
		<head>
		<meta charset='utf-8'/>
		<link rel='stylesheet' href='main.css'/>
		<title>#{pageHeader}</title>
		</head>
		<body>
		<center>
		<div class='content'>
		<header>#{pageHeader}</header>
		<img src='#{imagesrc}'/>
		<p>#{pageBody}</p>
		</div>
		</body>"


#YOU WILL HAVE TO MANUALLY ADJUST THE CSS LATER
cssResult="
		*{font-family: verdana;}
		body{
			display:block;
			background-color: gray ;
			}
		header{
			margin: auto;
			width: 60%;
			margin-bottom: 50px;
			margin-top: 10px;
			font-size: 60px;
			color: white;
			background-color: black;
			border-radius: 5px;
			}
		.content{
			background-color: LemonChiffon;
			width: 75%;
			border: 2px solid black;
			opacity: 0.9;
			}
		p{
			width: 80%;
			}
		hr{
			width: 80%;
			height: 8px;
			background-color: green;
		}
			"#manually adjust the CSS as you like before you make it. I'll add in better CSS management later, maybe leave this as Default




File.open('index.html', 'w+') do |f|
  f.write result
end
File.open('main.css', 'w+') do |f| #<= spent 15 minutes debugging, only to find I didn't put the w+ in quotes
  f.write cssResult
end


##########Cha-Cha-Cha-Cha-CHANGES###########
#1/31/19 I'll add in the list manually for the Saving Money site cause I'm bored, but later I'll put in a method to allow you to make a <ul> via CMD