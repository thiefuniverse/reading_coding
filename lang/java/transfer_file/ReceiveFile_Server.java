package com.example;

/**
 * Created by thief on 16-6-14.
 */

import java.net.ServerSocket;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.RandomAccessFile;
import java.net.ServerSocket;
import java.net.Socket;

import javax.swing.JFileChooser;

/**
 * Created by thief on 16-6-14.
 */

public class ReceiveFile_Server extends Thread{

    boolean isServer;

    //等待对方连接和文件发送
    ServerSocket serveSocket;

    boolean FileCompleted=false;

    Socket tempSocket;

    InputStream inSocket;

    RandomAccessFile inFile=null;

    BufferedReader readerName;

    byte receBuffer[]=new byte[1024];
    String receiveFileName;

    int defaultBindPort=12346;


    public ReceiveFile_Server()throws Exception
    {
        //绑定服务端口
        this.bindServerPort();

        //JFileChooser choosePath=new JFileChooser(".");
        //choosePath.showSaveDialog(new javax.swing.JFrame());



    }


    public void run()
    {
        try
        {

            System.out.println("Waiting .....");
            tempSocket=serveSocket.accept();
            this.serveSocket.setSoTimeout(5000);
            this.inSocket=tempSocket.getInputStream();
        }catch (Exception ex)
        {
            System.out.println(ex.toString());
            ex.printStackTrace();
            return;
        }


        //传输文件和套接字关闭
        int amount;

        try
        {

            readerName=new BufferedReader(new InputStreamReader(inSocket));

            receiveFileName=readerName.readLine();


            //获取当前文件引用
            //File savedFile=new File("/wonderDownload/"+receiveFileName,"w");
            File savedFile=new File(receiveFileName);

            if(savedFile!=null)
            {
                inFile=new RandomAccessFile(savedFile,"rw");
            }

            if(this.inFile==null)
            {
                System.out.println("No selected file!!!");

                this.serveSocket.close();
                return;
            }


            while((amount=inSocket.read(receBuffer))!=-1)
            {
                inFile.write(receBuffer,0,amount);

            }
            inSocket.close();
            inFile.close();
            System.out.println("Receive File completed!!");

        }catch (IOException e)
        {
            System.out.println(e.toString());
            e.printStackTrace();
        }
    }


    private void bindServerPort() throws IOException
    {
        serveSocket=new ServerSocket(this.defaultBindPort);
    }

    public static void main(String args[])
    {
        ReceiveFile receFile=null;

        try
        {
            receFile=new ReceiveFile();
            receFile.start();
        }catch (Exception e)
        {
            e.printStackTrace();
        }
        // while(true)
    }

}
