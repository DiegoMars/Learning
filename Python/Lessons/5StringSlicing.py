# slicing = create a substring by extracting elements from another string
# Can be down using [], where [start:stop(exclusive):step]
name = "Diego Martinez"
firstName = name[0:5] #or [:5]
print(firstName)
lastName = name[6:] #from 6 to the end
print(lastName)
funkyName = name[::2] #from start to end
print(funkyName)

reversedName = name[::-1] #steps backwards
print(reversedName)

# You can also use slcing function, (start,stop,step)
website = "http://google.com"
slice = slice(7,-4) #grabs only the google part
print(website[slice])

website2 = "http://wikipedia.com"
print(website2[slice])