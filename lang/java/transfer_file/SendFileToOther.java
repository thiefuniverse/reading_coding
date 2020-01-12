package com.example;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.RandomAccessFile;
import java.net.InetAddress;
import java.net.Socket;
import java.nio.Buffer;

import com.example.SelectWindow;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

/**
 * Created by thief on 16-6-7.
 */
public class SendFileToOther {

    String remoteIPString=null;

    Socket tempSocket;

    private String receiveIp;
    private String serverIP="127.0.0.1";
    private int serverPort=12346;

    private String fileName;

    //选择的发送文件
    File fileToSend;

    //远程文件接收端口
    int port=12345;
    //要发送的文件
    RandomAccessFile fastReadFile;
    //发送文件的输出流
    OutputStream outSocket;

    BufferedWriter writeName;

    //发送文件缓冲区
    byte sendBuffer[]=new byte[1024];


    public void getIp(String yourIp)
    {
        receiveIp=yourIp;
    }

    public boolean judgeIpReachable(String ip) throws IOException
    {
        InetAddress judgeInet=InetAddress.getByName(ip);
        return judgeInet.isReachable(100);
    }

    //对当前输入的ip发出连接请求,如果可以连接则开始选择文件传送
    public void handleIp() throws IOException, ClassNotFoundException, UnsupportedLookAndFeelException, InstantiationException, IllegalAccessException {


      //  SelectWindow chooseFile=new SelectWindow();
        getFilePath();

        if(fileToSend!=null)
        {
            fastReadFile=new RandomAccessFile(fileToSend,"rw");
        }

        //测试接收方是否在线,若不在线则发给缓存服务器
        if(judgeIpReachable(receiveIp))
        {
            this.remoteIPString=receiveIp;
            this.port=port;
            this.tempSocket=new Socket(this.remoteIPString,this.port);
            boolean judgeConnected=tempSocket.isConnected();

            if(judgeConnected)
            {
                sendFile();

            }
            else
            {
                this.remoteIPString=serverIP;
                this.port=serverPort;
                this.tempSocket=new Socket(this.remoteIPString,this.port);
                sendFile();
            }
        }

}
    public void sendFile()
    {
        try
        {


            System.out.println("connect Server successfully!!");

            outSocket=tempSocket.getOutputStream();

            int amount;
            System.out.println("Send starting ...");

            //将文件名写入socket流头部
            writeName=new BufferedWriter(new OutputStreamWriter(outSocket));
            writeName.write(fileName);
            writeName.newLine();
            writeName.flush();
            //writeName.close();




            while((amount=fastReadFile.read(sendBuffer))!=-1)
            {
                outSocket.write(sendBuffer,0,amount);
                System.out.println("File sending ....");
            }

            System.out.println("Send File completed!");

            //关闭发送文件流和socket
            tempSocket.close();
            fastReadFile.close();

            javax.swing.JOptionPane.showMessageDialog(new javax.swing.JFrame(),"Send File Completed!","Info!", JOptionPane.PLAIN_MESSAGE);

        }catch (IOException e)
        {
            System.out.println(e.toString());
            e.printStackTrace();
        }

    }


    //选择文件并获取文件流
    public void getFilePath() throws FileNotFoundException,ClassNotFoundException, UnsupportedLookAndFeelException, InstantiationException, IllegalAccessException {
        String path=null;

        UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        JFileChooser jdir=new JFileChooser();
        jdir.setFileSelectionMode(JFileChooser.FILES_ONLY);

        jdir.setDialogTitle("连接成功!请选择你想发送的文件!");
        if(JFileChooser.APPROVE_OPTION==jdir.showOpenDialog(null))
        {
            fileToSend=jdir.getSelectedFile();

            //获取文件名
            fileName=jdir.getSelectedFile().getName();

            return;
        }
        fileToSend=null;
    }



}
