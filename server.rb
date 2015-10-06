require 'socket'

server = TCPServer.open(1026)
loop {

	client = server.accept
	client.puts(Time.now.ctime)
	client.puts " bye!"
	client.close
}
