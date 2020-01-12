package com.example;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.io.File;
import java.io.IOException;

import javax.swing.*;

/**
 * Created by thief on 16-5-11.
 */
public class SelectWindow extends JFrame{




    public void ipWindow()
    {
        JTextField getIp=new JTextField(20);
        JLabel inputInfo=new JLabel("请输入接收方的IP地址:");
        JButton selectFile=new JButton("选择文件");

        JPanel myBoard1=new JPanel();
        JPanel myBoard2=new JPanel();
        this.setLayout(new GridLayout());

        myBoard1.add(inputInfo);
        myBoard2.add(getIp);
        myBoard2.add(selectFile);

        myBoard2.setLayout(new FlowLayout());
        this.add(myBoard1);
        this.add(myBoard2);

        this.setSize(400,100);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setTitle("输入IP");


        selectFile.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String receIp=getIp.getText();

                    SendFileToOther hostManager=new SendFileToOther();
                    hostManager.getIp(receIp);
                    try {

                        hostManager.handleIp();

                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }

                } catch (ClassNotFoundException e1) {
                    e1.printStackTrace();
                } catch (UnsupportedLookAndFeelException e1) {
                    e1.printStackTrace();
                } catch (InstantiationException e1) {
                    e1.printStackTrace();
                } catch (IllegalAccessException e1) {
                    e1.printStackTrace();
                }
            }

        });

    }

    public static void main(String args[])
    {
        SelectWindow sendHand=new SelectWindow();
        sendHand.ipWindow();


    }

}
