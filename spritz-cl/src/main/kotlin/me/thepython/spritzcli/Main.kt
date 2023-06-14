package me.thepython.spritzcli

import spritz.SpritzEnvironment
import spritz.api.Config
import java.io.File

fun main(args: Array<String>) {
    val env = SpritzEnvironment(Config())
        .setWarningHandler(::println)
        .setErrorHandler(::println)
    if (args.isNotEmpty()) {
        // If we want to execute code from a file
        if (args[0].endsWith(".sz")) {
            val script = File(args[0])
            if(script.exists()) {
                env.evaluate(File(args[0]))
            }
            else {
                println("[ERROR]: That file does not exist!")
            }
        }
        else {
            println("[ERROR]: All files must use the .sz file extension!")
        }
    }
    else {
        println("Spritz-CLI v0.1-BETA")
        while (true) {
            print("> ")
            val input = readln()
            env.evaluate("cli.sz", input)
        }
    }
}