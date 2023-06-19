<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
</head>
<body>
  <h1>Minitalk</h1>
  <p>Minitalk is a project developed as part of the curriculum at 42, a coding school. It is a client-server application that allows two processes to communicate using only signals.</p>
  <h2>Installation</h2>
  <ol>
    <li>Clone the repository:</li>
    <pre><code>git clone git@github.com:hovhannisyangevorg/Minitalk.git</code></pre>
<li>Navigate to the project directory:</li>
<pre><code>cd Minitalk</code></pre>

<li>Compile the server:</li>
<pre><code>make server</code></pre>

<li>Compile the client:</li>
<pre><code>make client</code></pre>
  </ol>
  <h2>Usage</h2>
  <ol>
    <li>Start the server by running the following command:</li>
    <pre><code>./server</code></pre>
<li>In a separate terminal, run the client with the server's process ID (PID) as the first argument and the message to be sent as the second argument:</li>
<pre><code>./client [server_PID] [message]</code></pre>

<p>For example:</p>
<pre><code>./client 12345 Hello</code></pre>

<li>The client process will send the message to the server, which will receive and display it.</li>

<li>You can send multiple messages by running the client again with different messages.</li>
  </ol>
  <h2>Project Structure</h2>
  <p>The Minitalk project consists of the following files:</p>
  <ul>
    <li><code>src/server.c</code>: Contains the implementation of the server.</li>
    <li><code>src/client.c</code>: Contains the implementation of the client.</li>
    <li><code>src/utils.c</code>: Contains the helper functions for the program.</li>
    <li><code>Makefile</code>: Contains the build instructions for compiling the server and client.</li>
  </ul>
  <h2>Contributing</h2>
  <p>Contributions to the Minitalk project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.</p>
  <h2>License</h2>
  <p>The Minitalk project is open-source software licensed under the <a href="LICENSE">MIT license</a>. Feel free to use, modify, and distribute the code as per the terms of the license.</p>
</body>
</html>
